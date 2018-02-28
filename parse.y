%{     /* pars1.y    Pascal Parser      Gordon S. Novak Jr.  ; 30 Jul 13   */

/* Copyright (c) 2013 Gordon S. Novak Jr. and
   The University of Texas at Austin. */

/* 14 Feb 01; 01 Oct 04; 02 Mar 07; 27 Feb 08; 24 Jul 09; 02 Aug 12 */

/*
; This program is free software; you can redistribute it and/or modify
; it under the terms of the GNU General Public License as published by
; the Free Software Foundation; either version 2 of the License, or
; (at your option) any later version.

; This program is distributed in the hope that it will be useful,
; but WITHOUT ANY WARRANTY; without even the implied warranty of
; MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
; GNU General Public License for more details.

; You should have received a copy of the GNU General Public License
; along with this program; if not, see <http://www.gnu.org/licenses/>.
  */


/* NOTE:   Copy your lexan.l lexical analyzer to this directory.      */

       /* To use:
                     make pars1y              has 1 shift/reduce conflict
                     pars1y                   execute the parser
                     i:=j .
                     ^D                       control-D to end input

                     pars1y                   execute the parser
                     begin i:=j; if i+j then x:=a+b*c else x:=a*b+c; k:=i end.
                     ^D

                     pars1y                   execute the parser
                     if x+y then if y+z then i:=j else k:=2.
                     ^D

           You may copy pars1.y to be parse.y and extend it for your
           assignment.  Then use   make parser   as above.
        */

        /* Yacc reports 1 shift/reduce conflict, due to the ELSE part of
           the IF statement, but Yacc's default resolves it in the right way.*/

#include <stdio.h>
#include <ctype.h>
#include "token.h"
#include "lexan.h"
#include "symtab.h"
#include "parse.h"
#include "pprint.h"

        /* define the type of the Yacc stack element to be TOKEN */

#define YYSTYPE TOKEN

TOKEN parseresult;

%}

/* Order of tokens corresponds to tokendefs.c; do not change */

%token IDENTIFIER STRING NUMBER   /* token types */

%token PLUS MINUS TIMES DIVIDE    /* Operators */
%token ASSIGN EQ NE LT LE GE GT POINT DOT AND OR NOT DIV MOD IN

%token COMMA                      /* Delimiters */
%token SEMICOLON COLON LPAREN RPAREN LBRACKET RBRACKET DOTDOT

%token ARRAY BEGINBEGIN           /* Lex uses BEGIN */
%token CASE CONST DO DOWNTO ELSE END FILEFILE FOR FUNCTION GOTO IF LABEL NIL
%token OF PACKED PROCEDURE PROGRAM RECORD REPEAT SET THEN TO TYPE UNTIL
%token VAR WHILE WITH

%%

program : PROGRAM IDENTIFIER LPAREN id_list RPAREN SEMICOLON vblock DOT {parseresult = makeprogram($2, $4, $7); }


unsigned_constant : IDENTIFIER | NUMBER | NIL | STRING

sign : PLUS | MINUS

constant : sign | sign IDENTIFIER | IDENTIFIER| NUMBER | sign NUMBER | STRING

id_list : IDENTIFIER COMMA IDENTIFIER {$$ = cons($1,$3);} || IDENTIFIER {$$ = $1;}

simple_type : IDENTIFIER { $$ = findtype($1); }
            | LPAREN id_list RPAREN
            | constant DOTDOT constant

simple_type_list : simple_type
                 | simple_type COMMA simple_type_list

type : simple_type
     | ARRAY LBRACKET simple_type_list RBRACKET OF type
     | RECORD field_list END
     | POINT IDENTIFIER

fields : id_list COLON type

field_list : fields
           | fields SEMICOLON field_list

expr_list : expression|
            expression COMMA expr_list

variable : IDENTIFIER
         | variable LBRACKET expr_list RBRACKET
         | variable DOT IDENTIFIER
         | variable POINT

factor : unsigned_constant
       | variable
       | funcall
       | LPAREN expression RPAREN
       | NOT factor

funcall : IDENTIFIER LPAREN expr_list RPAREN {$$ = makefuncall($2, $1, $3);} 

times_op : TIMES | DIVIDE | DIV | MOD | AND

term : term times_op factor
     | factor

plus_op : PLUS | MINUS | OR

simple_expression : sign term | term
                  | simple_expression plus_op term

compare_op : EQ | LT | GT | NE | LE | GE | IN

expression : expression compare_op simple_expression
           | simple_expression {$$ = $1;}

numlist : NUMBER|
          NUMBER  COMMA numlist

lblock : LABEL numlist SEMICOLON cblock
       | cblock

cdef : IDENTIFIER EQ constant 

cdef_list : NIL | cdef SEMICOLON 

cblock : CONST cdef_list tblock
       | tblock

tdef : IDENTIFIER EQ type

tdef_list : NIL | tdef SEMICOLON 

tblock : TYPE tdef_list vblock
       | vblock

vdef : id_list COLON type {instvars($1, $3);}


vdef_list : vdef SEMICOLON 

vblock : VAR vdef_list block { $$ = $3 ; }
       | block

block : BEGINBEGIN statement endpart {$$ = cons($2,$3);}

/* endpart : SEMICOLON statement endpart
        | END */

label : NUMBER COLON statement

 statement : BEGINBEGIN statement endpart {$$ = makeprogn($1, cons($2,$3));}
          | IF expression THEN statement ELSE statement
          | IF expression THEN statement
          | variable ASSIGN expression {$$ = binop($2, $1, $3); } 
          | funcall    
          | WHILE expression DO statement
          | REPEAT statement UNTIL expression
          | FOR IDENTIFIER ASSIGN expression TO expression DO statement {$$ = makefor(1,$1, binop($3, $2, $4),$5,$6,$7, $8);}  
          | GOTO NUMBER
          | label 


/* statement_list : statement { $$ = makeprogn($1, $1); }
               | statement SEMICOLON statement_list {$$ = cons($1,makeprogn($1,$3)); }
             ; */
  endpart    :  SEMICOLON statement endpart    { $$ = cons($2, $3); }
             |  END                            { $$ = NULL; }
             ;
  endif      :  ELSE statement                 { $$ = $2; }
   assignment :  IDENTIFIER ASSIGN expr         { $$ = binop($2, $1, $3); }
             ;
  expr       :  expr PLUS term                 { $$ = binop($2, $1, $3); }
             |  term 
             ;
  term       :  term TIMES factor              { $$ = binop($2, $1, $3); }
             |  factor
             ;
  factor     :  LPAREN expr RPAREN             { $$ = $2; }
             |  IDENTIFIER
             |  NUMBER
             ; 

%%

/* You should add your own debugging flags below, and add debugging
   printouts to your programs.

   You will want to change DEBUG to turn off printouts once things
   are working.
  */

#define DEBUG        31             /* set bits here for debugging, 0 = off  */
#define DB_CONS       1             /* bit to trace cons */
#define DB_BINOP      2             /* bit to trace binop */
#define DB_MAKEIF     4             /* bit to trace makeif */
#define DB_MAKEPROGN  8             /* bit to trace makeprogn */
#define DB_PARSERES  16             /* bit to trace parseresult */

 int labelnumber = 0;  /* sequential counter for internal label numbers */

   /*  Note: you should add to the above values and insert debugging
       printouts in your routines similar to those that are shown here.     */


TOKEN makeprogram (TOKEN name, TOKEN args, TOKEN statements)
{
TOKEN optok = talloc();
TOKEN argtok = talloc();
TOKEN statement_tok = talloc();

optok->tokentype = OPERATOR;
optok->whichval = PROGRAMOP;
optok-> operands = name;

argtok = makeprogn(argtok , args);
statement_tok = makeprogn(statement_tok , statements);
name -> link = argtok;
argtok -> link = statement_tok;
return optok;
}

TOKEN makefuncall(TOKEN tok, TOKEN fn, TOKEN args)
{

tok->tokentype = OPERATOR;
tok->whichval = FUNCALLOP;
tok->operands = fn;
fn->link = args;
return tok;

}

TOKEN copytok(TOKEN origtok)
{
  TOKEN newtok = talloc();
 *newtok = *origtok;
  newtok -> link = NULL;
  newtok -> operands = NULL;

}

TOKEN makefor(int sign, TOKEN tok, TOKEN asg, TOKEN tokb, TOKEN endexpr,
              TOKEN tokc, TOKEN statement)
{


TOKEN answer = talloc();
TOKEN extra_tok = talloc();
TOKEN extra_link = talloc();
TOKEN label_tok = talloc();
TOKEN if_tok = talloc();
TOKEN func_tok = talloc();
TOKEN less_than = talloc();
TOKEN less_than_link = talloc();
TOKEN expres = talloc(); 
TOKEN numtok = talloc();
TOKEN assign_tok = talloc();
TOKEN expres_cpy = talloc();
TOKEN plus_op = talloc();
TOKEN expres_cpy2 = talloc();
TOKEN numtok2 = talloc(); 
TOKEN goto_tok = talloc();
TOKEN func_tokcpy = talloc(); 

// function call
 func_tok = makeprogn(func_tok, statement);

// num label token
  numtok->tokentype = NUMBERTOK;
  numtok->basicdt = INTEGER;
  numtok->intval = 0;

  numtok2->tokentype = NUMBERTOK;
  numtok2->basicdt = INTEGER;
  numtok2->intval = 1;

// variable i 
  expres = copytok(asg->operands);

// less than token 
 less_than->tokentype = OPERATOR;
 less_than -> whichval = LEOP;
 less_than->operands = expres;
 
 less_than-> link = func_tok;

 // func_tok->operands = statement;
 expres -> link = endexpr;
 endexpr->link = NULL;

// label token
  label_tok->tokentype = OPERATOR;
  label_tok -> whichval = LABELOP;
  label_tok->operands = numtok;
  
// if token
  if_tok->tokentype = OPERATOR;
  if_tok->whichval = IFOP;
  if_tok->operands = less_than; 


// increment token
  expres_cpy = copytok(expres);
  assign_tok->tokentype = OPERATOR;
  assign_tok -> whichval = ASSIGNOP;
  assign_tok->operands = expres_cpy;
//  statement->link = assign_tok;

func_tokcpy = func_tok->operands;

  plus_op->tokentype = OPERATOR;
  plus_op -> whichval = PLUSOP;
  plus_op->operands = expres_cpy2;
  expres_cpy ->link = plus_op;
  expres_cpy2->link = numtok2; 

  goto_tok->tokentype = OPERATOR;
  goto_tok->whichval = GOTOOP;
  goto_tok->operands = numtok;

 assign_tok->link = goto_tok;

answer = makeprogn(answer, asg);
extra_tok =answer->operands;
extra_tok->link = label_tok;
label_tok->link = if_tok;










 
  /*  TOKEN assign_tok = talloc();
  TOKEN red_cond = talloc();
  TOKEN condtok = talloc();  
  TOKEN numtok = talloc();
  TOKEN iftok = talloc();
  TOKEN goto_tok = talloc();
  TOKEN inc_tok = talloc();  

  // num label token
  numtok->tokentype = NUMBERTOK;
  numtok->basicdt = INTEGER;
  numtok->intval = 0;

  inc_tok->tokentype = NUMBERTOK;
  inc_tok->basicdt = INTEGER;
  inc_tok->intval = 1;

  // label token
  tok->tokentype = OPERATOR;
  tok -> whichval = LABELOP;
  tok->operands = numtok;

  // conditional token
  condtok->tokentype = OPERATOR;
  condtok -> whichval = LEOP;
  

   // if token
  iftok->tokentype = OPERATOR;
  iftok->whichval = IFOP;
  
  iftok->operands =  binop(condtok,copytok(asg->operands),endexpr);


  // assignment and label link
  asg->link = tok;
  
   // link label to if
   tok->link = iftok;
  

 
  // if tokens operand is condtok 
  condtok->link = statement;
 

  // increment token
  assign_tok->tokentype = OPERATOR;
  assign_tok -> whichval = ASSIGNOP;
  assign_tok->operands = asg->operands;
  (copytok(assign_tok->operands))->link =  binop(PLUSOP, copytok(asg->operands),sign); 
  
  copytok((statement->operands))->link = assign_tok;   

  goto_tok->tokentype = OPERATOR;
  goto_tok->whichval = GOTOOP;
  goto_tok->operands = numtok;
   assign_tok->link = goto_tok;
   return asg; */

return answer;

}



TOKEN findtype (TOKEN tok)
{
 SYMBOL symbtype = searchst(tok->stringval);
 tok->symtype = symbtype;
 return tok;

}

void instconst(TOKEN idtok, TOKEN consttok)
{
printf("IN INSTCONST");
SYMBOL varsymb = searchst(idtok->stringval );
varsymb->kind = CONSTSYM;
varsymb->basicdt = consttok->basicdt;
varsymb->size = sizeof(varsymb->basicdt);
varsymb->constval.intnum = consttok -> intval;
consttok -> tokentype = NUMBERTOK;

}

/* install variables in symbol table */
void instvars(TOKEN idlist, TOKEN typetok)
{
 SYMBOL sym, typesym; int align;
  typesym = typetok->symtype;
  align = alignsize(typesym);
  while ( idlist != NULL ) /* for each id */
  { 
    sym = insertsym(idlist->stringval);
    sym->kind = VARSYM;
    sym->offset = /* "next" */
    wordaddress(blockoffs[blocknumber],
    align);
    sym->size = typesym->size;
    blockoffs[blocknumber] = /* "next" */
    sym->offset + sym->size;
    sym->datatype = typesym;
   sym->basicdt = typesym->basicdt;
   idlist = idlist->link;
};
}

TOKEN findid(TOKEN tok) { /* the ID token */
SYMBOL sym, typ;
sym = searchst(tok->stringval);
tok->symentry = sym;
typ = sym->datatype;
tok->symtype = typ;
if ( typ->kind == BASICTYPE ||
typ->kind == POINTERSYM)
tok->basicdt = typ->basicdt;
return tok;
}


TOKEN cons(TOKEN item, TOKEN list)           /* add item to front of list */
  { item->link = list;
    if (DEBUG & DB_CONS)
       { printf("cons\n");
         dbugprinttok(item);
         dbugprinttok(list);
       };
    return item;
  }

TOKEN binop(TOKEN op, TOKEN lhs, TOKEN rhs)        /* reduce binary operator */
  { op->operands = lhs;          /* link operands to operator       */
    lhs->link = rhs;             /* link second operand to first    */
    rhs->link = NULL;            /* terminate operand list          */
    if (DEBUG & DB_BINOP)
       { printf("binop\n");
         dbugprinttok(op);
         dbugprinttok(lhs);
         dbugprinttok(rhs);
       };
    return op;
  }

TOKEN makeif(TOKEN tok, TOKEN exp, TOKEN thenpart, TOKEN elsepart)
  {  tok->tokentype = OPERATOR;  /* Make it look like an operator   */
     tok->whichval = IFOP;
     if (elsepart != NULL) elsepart->link = NULL;
     thenpart->link = elsepart;
     exp->link = thenpart;
     tok->operands = exp;
     if (DEBUG & DB_MAKEIF)
        { printf("makeif\n");
          dbugprinttok(tok);
          dbugprinttok(exp);
          dbugprinttok(thenpart);
          dbugprinttok(elsepart);
        };
     return tok;
   }

TOKEN makeprogn(TOKEN tok, TOKEN statements)
  {  tok->tokentype = OPERATOR;
     tok->whichval = PROGNOP;
     tok->operands = statements;
     if (DEBUG & DB_MAKEPROGN)
       { printf("makeprogn\n");
         dbugprinttok(tok);
         dbugprinttok(statements);
       };
     return tok;
   }

int wordaddress(int n, int wordsize)
  { return ((n + wordsize - 1) / wordsize) * wordsize; }
 
void yyerror (char const *s)
{
  fprintf (stderr, "%s\n", s);
}

int main(void)          /*  */
  { int res;
    initsyms();
    res = yyparse();
//    printst();       /* to shorten, change to:  printstlevel(1);  */
    printf("yyparse result = %8d\n", res);
    if (DEBUG & DB_PARSERES) dbugprinttok(parseresult);
    ppexpr(parseresult);           /* Pretty-print the result tree */
    /* uncomment following to call code generator. */
     /* 
    gencode(parseresult, blockoffs[blocknumber], labelnumber);
 */
  }


/* lex1.c         14 Feb 01; 31 May 12; 11 Jan 18       */

/* This file contains code stubs for the lexical analyzer.
   Rename this file to be lexanc.c and fill in the stubs.    */

/* Copyright (c) 2018 Gordon S. Novak Jr. and
   The University of Texas at Austin. */

/*
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "token.h"
#include "lexan.h"

static char *resprnt[] = { " ", "array", "begin", "case", "const", "do",
                           "downto", "else", "end", "file", "for",
                           "function", "goto", "if", "label", "nil",
                           "of", "packed", "procedure", "program", "record",
                           "repeat", "set", "then", "to", "type",
                           "until", "var", "while", "with" };
static char* opprnt[]  = {" ", "+", "-", "*", "/", ":=", "=", "<>", "<", "<=",
                          ">=", ">",  "^", ".", "and", "or", "not", "div",
                          "mod", "in", "if", "goto", "progn", "label",
                          "funcall", "aref", "program", "float"};
static char *delprnt[] = { "  ", " ,", " ;", " :", " (", " )", " [", " ]",
                           ".."} ;


/* This file will work as given with an input file consisting only
   of integers separated by blanks:
   make lex1
   lex1
   12345 123    345  357
   */

/* Skip blanks and whitespace.  Expand this function to skip comments too. */
void skipblanks ()
  {
      int c;
      int sec;

      while ((c = peekchar()) != EOF
             && (c == ' ' || c == '\n' || c == '\t') || c == '{' ||(c == '(' && (sec = peek2char()) != EOF && sec == '*' ))
      {
      if (c == '{')
      {
        getchar();
	while ((c = peekchar() !='}') && c!= EOF)
         getchar();
	getchar();
      }

     // skip (* *) comments
      else if( c  == '(' && sec == '*' )
      {
        getchar();
        getchar();
        while((c = peekchar() != '*') && (sec= peek2char() != ')') && c!= EOF && sec != EOF )
          getchar();

	getchar();
	getchar();
      }

      else
	getchar();

    }
}

/* Get identifiers and reserved words */
TOKEN identifier (TOKEN tok)
  {
	int c;
        int length = 0;
        char mystring[16];
	int is_res;
	int is_res_op;

	while (( c = peekchar()) !=  EOF && (CHARCLASS[c] == ALPHA || CHARCLASS[c] == NUMERIC))
	{
	  c = getchar();
	  if (length < 15)
		mystring[length] = c;
		length++;
	}
	
	 mystring[length] = '\0';


	
	
	for(int count = 1; count < 30; count++)
	{
	  is_res = strcmp(mystring, resprnt[count]);
	  if (is_res == 0)
	  {
		tok -> tokentype = RESERVED;
		tok -> whichval = count;
		return tok;
	  }

	}

	 for(int count = 14; count < 20; count++)
        {
          is_res_op = strcmp(mystring, opprnt[count]);
          if (is_res_op == 0)
          {
                tok -> tokentype = OPERATOR;
                tok -> whichval = count;
                return tok;
          }

        }


	if (is_res != 0 )
	{
		tok -> tokentype = IDENTIFIERTOK;
		strcpy(tok -> stringval, mystring);
	}
	return tok; 



  }

TOKEN getstring (TOKEN tok)
  {
		
	int c;
        int length = 0;
        char mystring[16];
        int is_res;
	getchar();
	int next;

        while (( c = peekchar()) !=  EOF && (CHARCLASS[c] == ALPHA || CHARCLASS[c] == NUMERIC || c == '\''))
        {
          if (length < 15)
	    if (c == '\'' && (next = peek2char()) == '\'')
	    {
	      mystring[length] = c;
	      length++;
	      getchar();
	      getchar();
	    }	
	     else if (c == '\'')
	     {
		getchar();
	     }

	     else
	     {
		mystring[length] = c;
                length++;
		getchar();

	     }
           else 
	    getchar();
        }

         mystring[length] = '\0';

	tok -> tokentype = STRINGTOK;
                strcpy(tok -> stringval, mystring);
	return tok;


  }

TOKEN special (TOKEN tok)
  {

	int c;
        int length = 0;
        char mystring[16];
	int is_op;
	int is_del;

	while (( c = peekchar()) !=  EOF && (CHARCLASS[c] == SPECIAL))
	{
	  c = getchar();
	  mystring[length] = c;
                length++;
	}

	mystring[length] = '\0';
	
	for(int count = 1; count < 14; count++)
        {
          is_op = strcmp(mystring, opprnt[count]);
          if (is_op == 0)
          {
                tok -> tokentype = OPERATOR;
                tok -> whichval = count;
                return tok;
          }

        }

	for(int count = 1; count < 9; count++)
        {
          is_del = strcmp(mystring, delprnt[count]);
          if (is_del == 0)
          {
                tok -> tokentype = DELIMITER;
                tok -> whichval = count;
                return tok;
          }

        }

	


  }

/* Get and convert unsigned numbers of all types. */
TOKEN number (TOKEN tok)
  { long num;
    int  c, charval;
    num = 0;
    while ( (c = peekchar()) != EOF
            && CHARCLASS[c] == NUMERIC)
      {   c = getchar();
          charval = (c - '0');
          num = num * 10 + charval;
        }
    tok->tokentype = NUMBERTOK;
    tok->basicdt = INTEGER;
    tok->intval = num;
    return (tok);
  }


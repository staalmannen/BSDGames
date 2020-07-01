typedef unsigned char Uchar;
# include <stdio.h>
# define U(x) x
# define NLSTATE yyprevious=YYNEWLINE
# define BEGIN yybgin = yysvec + 1 +
# define INITIAL 0
# define YYLERR yysvec
# define YYSTATE (yyestate-yysvec-1)
# define YYOPTIM 1
# define YYLMAX 200
# define unput(c) {yytchar= (c);if(yytchar=='\n')yylineno--;*yysptr++=yytchar;}
# define yymore() (yymorfg=1)
//# define ECHO fprintf(yyout, "%s",yytext)
# define REJECT { nstr = yyreject(); goto yyfussy;}
int yyleng; extern char yytext[];
int yymorfg;
extern Uchar *yysptr, yysbuf[];
int yytchar;
FILE *yyin = {stdin}, *yyout = {stdout};
extern int yylineno;
struct yysvf { 
	struct yywork *yystoff;
	struct yysvf *yyother;
	int *yystops;};
struct yysvf *yyestate;
extern struct yysvf yysvec[], *yybgin;
int yylook(void), yywrap(void), yyback(int *, int);
# define output(c) putc(c,yyout)
# define input() (((yytchar=yysptr>yysbuf?U(*--yysptr):getc(yyin))==10?(yylineno++,yytchar):yytchar)==EOF?0:yytchar)
/*	$NetBSD: lex.l,v 1.7 2003/08/07 09:36:54 agc Exp $	*/

/*-
 * Copyright (c) 1990, 1993
 *	The Regents of the University of California.  All rights reserved.
 *
 * This code is derived from software contributed to Berkeley by
 * Ed James.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

/*
 * Copyright (c) 1987 by Ed James, UC Berkeley.  All rights reserved.
 *
 * Copy permission is hereby granted provided that this notice is
 * retained on all partial or complete copies.
 *
 * For more info on this and all of my stuff, mail edjames@berkeley.edu.
 */

#include <sys/cdefs.h>
#ifndef lint
#if 0
static char sccsid[] = "@(#)lex.l	8.1 (Berkeley) 5/31/93";
#else
__RCSID("$NetBSD: lex.l,v 1.7 2003/08/07 09:36:54 agc Exp $");
#endif
#endif /* not lint */

#include "include.h"
//#undef ECHO		/* XXX: work around lex(1) vs termios lameness */
#include "grammar.h"

extern int	line;

#define YYNEWLINE 10
yylex(void){
int nstr; extern int yyprevious;
while((nstr = yylook()) >= 0)
yyfussy: switch(nstr){
case 0:
if(yywrap()) return(0); break;
case 1:
		{ yylval.ival = atoi(yytext);  return(ConstOp); }
break;
case 2:
		{ return(HeightOp); }
break;
case 3:
		{ return(WidthOp); }
break;
case 4:
	{ return(NewplaneOp); }
break;
case 5:
		{ return(UpdateOp); }
break;
case 6:
		{ return(AirportOp); }
break;
case 7:
		{ return(LineOp); }
break;
case 8:
		{ return(ExitOp); }
break;
case 9:
		{ return(BeaconOp); }
break;
case 10:
	{ yylval.cval = *yytext; return (DirOp); }
break;
case 11:
		{ }
break;
case 12:
	{ line++; }
break;
case 13:
		{ line++; }
break;
case 14:
		{ return *yytext; }
break;
case -1:
break;
default:
fprintf(yyout,"bad switch yylook %d",nstr);
} return(0); }
/* end of yylex */
int yyvstop[] = {
0,

14,
0,

11,
14,
0,

13,
0,

14,
0,

1,
14,
0,

10,
14,
0,

14,
0,

10,
14,
0,

10,
14,
0,

14,
0,

14,
0,

14,
0,

14,
0,

10,
14,
0,

11,
0,

12,
0,

1,
0,

8,
0,

7,
0,

3,
0,

9,
0,

2,
0,

5,
0,

6,
0,

4,
0,
0};
# define YYTYPE Uchar
struct yywork { YYTYPE verify, advance; } yycrank[] = {
0,0,	0,0,	1,3,	0,0,	
0,0,	0,0,	0,0,	6,18,	
0,0,	0,0,	1,4,	1,5,	
4,17,	0,0,	0,0,	6,18,	
6,19,	0,0,	0,0,	0,0,	
0,0,	0,0,	0,0,	0,0,	
0,0,	0,0,	0,0,	0,0,	
0,0,	0,0,	0,0,	0,0,	
0,0,	0,0,	0,0,	4,17,	
1,6,	0,0,	0,0,	0,0,	
0,0,	0,0,	0,0,	0,0,	
0,0,	0,0,	0,0,	0,0,	
0,0,	1,7,	0,0,	0,0,	
0,0,	0,0,	6,18,	0,0,	
0,0,	0,0,	0,0,	0,0,	
0,0,	2,6,	7,20,	7,20,	
7,20,	7,20,	7,20,	7,20,	
7,20,	7,20,	7,20,	7,20,	
0,0,	0,0,	0,0,	0,0,	
0,0,	0,0,	0,0,	0,0,	
0,0,	0,0,	0,0,	0,0,	
0,0,	0,0,	0,0,	0,0,	
0,0,	0,0,	0,0,	0,0,	
0,0,	0,0,	0,0,	0,0,	
0,0,	0,0,	1,8,	1,9,	
1,10,	1,10,	1,11,	6,18,	
9,22,	1,12,	8,21,	12,24,	
13,25,	1,13,	14,26,	1,14,	
16,28,	15,27,	1,10,	21,29,	
22,30,	23,31,	1,15,	24,32,	
1,16,	1,10,	11,23,	1,10,	
2,9,	2,10,	2,10,	2,11,	
25,33,	26,34,	2,12,	27,35,	
28,36,	29,37,	2,13,	30,38,	
2,14,	31,39,	32,40,	2,10,	
33,41,	34,42,	35,43,	2,15,	
36,44,	2,16,	2,10,	37,45,	
2,10,	38,46,	40,47,	42,48,	
43,49,	44,50,	45,51,	46,52,	
47,53,	48,54,	49,55,	51,56,	
54,57,	57,58,	0,0,	0,0,	
0,0};
struct yysvf yysvec[] = {
0,	0,	0,
yycrank+-1,	0,		0,	
yycrank+-26,	yysvec+1,	0,	
yycrank+0,	0,		yyvstop+1,
yycrank+3,	0,		yyvstop+3,
yycrank+0,	0,		yyvstop+6,
yycrank+-6,	0,		yyvstop+8,
yycrank+14,	0,		yyvstop+10,
yycrank+1,	0,		yyvstop+13,
yycrank+3,	0,		yyvstop+16,
yycrank+0,	0,		yyvstop+18,
yycrank+2,	0,		yyvstop+21,
yycrank+6,	0,		yyvstop+24,
yycrank+3,	0,		yyvstop+26,
yycrank+9,	0,		yyvstop+28,
yycrank+1,	0,		yyvstop+30,
yycrank+7,	0,		yyvstop+32,
yycrank+0,	yysvec+4,	yyvstop+35,
yycrank+0,	yysvec+6,	0,	
yycrank+0,	0,		yyvstop+37,
yycrank+0,	yysvec+7,	yyvstop+39,
yycrank+1,	0,		0,	
yycrank+19,	0,		0,	
yycrank+12,	0,		0,	
yycrank+14,	0,		0,	
yycrank+18,	0,		0,	
yycrank+10,	0,		0,	
yycrank+31,	0,		0,	
yycrank+32,	0,		0,	
yycrank+21,	0,		0,	
yycrank+36,	0,		0,	
yycrank+21,	0,		0,	
yycrank+35,	0,		0,	
yycrank+39,	0,		0,	
yycrank+29,	0,		0,	
yycrank+45,	0,		0,	
yycrank+28,	0,		0,	
yycrank+36,	0,		0,	
yycrank+38,	0,		0,	
yycrank+0,	0,		yyvstop+41,
yycrank+46,	0,		0,	
yycrank+0,	0,		yyvstop+43,
yycrank+43,	0,		0,	
yycrank+36,	0,		0,	
yycrank+49,	0,		0,	
yycrank+40,	0,		0,	
yycrank+45,	0,		0,	
yycrank+40,	0,		0,	
yycrank+60,	0,		0,	
yycrank+57,	0,		0,	
yycrank+0,	0,		yyvstop+45,
yycrank+43,	0,		0,	
yycrank+0,	0,		yyvstop+47,
yycrank+0,	0,		yyvstop+49,
yycrank+50,	0,		0,	
yycrank+0,	0,		yyvstop+51,
yycrank+0,	0,		yyvstop+53,
yycrank+60,	0,		0,	
yycrank+0,	0,		yyvstop+55,
0,	0,	0};
struct yywork *yytop = yycrank+161;
struct yysvf *yybgin = yysvec+1;
Uchar yymatch[] = {
00  ,01  ,01  ,01  ,01  ,01  ,01  ,01  ,
01  ,011 ,012 ,01  ,01  ,01  ,01  ,01  ,
01  ,01  ,01  ,01  ,01  ,01  ,01  ,01  ,
01  ,01  ,01  ,01  ,01  ,01  ,01  ,01  ,
011 ,01  ,01  ,01  ,01  ,01  ,01  ,01  ,
01  ,01  ,01  ,01  ,01  ,01  ,01  ,01  ,
'0' ,'0' ,'0' ,'0' ,'0' ,'0' ,'0' ,'0' ,
'0' ,'0' ,01  ,01  ,01  ,01  ,01  ,01  ,
01  ,01  ,01  ,01  ,01  ,01  ,01  ,01  ,
01  ,01  ,01  ,01  ,01  ,01  ,01  ,01  ,
01  ,01  ,01  ,01  ,01  ,01  ,01  ,01  ,
01  ,01  ,01  ,01  ,01  ,01  ,01  ,01  ,
01  ,'a' ,01  ,'a' ,'a' ,'a' ,01  ,01  ,
01  ,01  ,01  ,01  ,01  ,01  ,01  ,01  ,
01  ,'a' ,01  ,01  ,01  ,01  ,01  ,'a' ,
'a' ,01  ,'a' ,01  ,01  ,01  ,01  ,01  ,
01  ,01  ,01  ,01  ,01  ,01  ,01  ,01  ,
01  ,01  ,01  ,01  ,01  ,01  ,01  ,01  ,
01  ,01  ,01  ,01  ,01  ,01  ,01  ,01  ,
01  ,01  ,01  ,01  ,01  ,01  ,01  ,01  ,
01  ,01  ,01  ,01  ,01  ,01  ,01  ,01  ,
01  ,01  ,01  ,01  ,01  ,01  ,01  ,01  ,
01  ,01  ,01  ,01  ,01  ,01  ,01  ,01  ,
01  ,01  ,01  ,01  ,01  ,01  ,01  ,01  ,
01  ,01  ,01  ,01  ,01  ,01  ,01  ,01  ,
01  ,01  ,01  ,01  ,01  ,01  ,01  ,01  ,
01  ,01  ,01  ,01  ,01  ,01  ,01  ,01  ,
01  ,01  ,01  ,01  ,01  ,01  ,01  ,01  ,
01  ,01  ,01  ,01  ,01  ,01  ,01  ,01  ,
01  ,01  ,01  ,01  ,01  ,01  ,01  ,01  ,
01  ,01  ,01  ,01  ,01  ,01  ,01  ,01  ,
01  ,01  ,01  ,01  ,01  ,01  ,01  ,01  ,
0};
Uchar yyextra[] = {
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0};
#pragma lib	"libl.a"
int yylineno =1;
# define YYU(x) x
char yytext[YYLMAX];
struct yysvf *yylstate [YYLMAX], **yylsp, **yyolsp;
Uchar yysbuf[YYLMAX];
Uchar *yysptr = yysbuf;
int *yyfnd;
extern struct yysvf *yyestate;
int yyprevious = YYNEWLINE;
# ifdef LEXDEBUG
extern void allprint(int);
# endif
yylook(void){
	struct yysvf *yystate, **lsp;
	struct yywork *yyt;
	struct yysvf *yyz;
	int yych;
	struct yywork *yyr;
# ifdef LEXDEBUG
	int debug;
# endif
	Uchar *yylastch;
	/* start off machines */
# ifdef LEXDEBUG
	debug = 0;
# endif
	if (!yymorfg)
		yylastch = (Uchar*)yytext;
	else {
		yymorfg=0;
		yylastch = (Uchar*)yytext+yyleng;
		}
	for(;;){
		lsp = yylstate;
		yyestate = yystate = yybgin;
		if (yyprevious==YYNEWLINE) yystate++;
		for (;;){
# ifdef LEXDEBUG
			if(debug)fprintf(yyout,"state %d\n",yystate-yysvec-1);
# endif
			yyt = yystate->yystoff;
			if(yyt == yycrank){		/* may not be any transitions */
				yyz = yystate->yyother;
				if(yyz == 0)break;
				if(yyz->yystoff == yycrank)break;
				}
			*yylastch++ = yych = input();
		tryagain:
# ifdef LEXDEBUG
			if(debug){
				fprintf(yyout,"char ");
				allprint(yych);
				putchar('\n');
				}
# endif
			yyr = yyt;
			if (yyt > yycrank){
				yyt = yyr + yych;
				if (yyt <= yytop && yyt->verify+yysvec == yystate){
					if(yyt->advance+yysvec == YYLERR)	/* error transitions */
						{unput(*--yylastch);break;}
					*lsp++ = yystate = yyt->advance+yysvec;
					goto contin;
					}
				}
# ifdef YYOPTIM
			else if(yyt < yycrank) {	/* r < yycrank */
				yyt = yyr = yycrank+(yycrank-yyt);
# ifdef LEXDEBUG
				if(debug)fprintf(yyout,"compressed state\n");
# endif
				yyt = yyt + yych;
				if(yyt <= yytop && yyt->verify+yysvec == yystate){
					if(yyt->advance+yysvec == YYLERR)	/* error transitions */
						{unput(*--yylastch);break;}
					*lsp++ = yystate = yyt->advance+yysvec;
					goto contin;
					}
				yyt = yyr + YYU(yymatch[yych]);
# ifdef LEXDEBUG
				if(debug){
					fprintf(yyout,"try fall back character ");
					allprint(YYU(yymatch[yych]));
					putchar('\n');
					}
# endif
				if(yyt <= yytop && yyt->verify+yysvec == yystate){
					if(yyt->advance+yysvec == YYLERR)	/* error transition */
						{unput(*--yylastch);break;}
					*lsp++ = yystate = yyt->advance+yysvec;
					goto contin;
					}
				}
			if ((yystate = yystate->yyother) && (yyt= yystate->yystoff) != yycrank){
# ifdef LEXDEBUG
				if(debug)fprintf(yyout,"fall back to state %d\n",yystate-yysvec-1);
# endif
				goto tryagain;
				}
# endif
			else
				{unput(*--yylastch);break;}
		contin:
# ifdef LEXDEBUG
			if(debug){
				fprintf(yyout,"state %d char ",yystate-yysvec-1);
				allprint(yych);
				putchar('\n');
				}
# endif
			;
			}
# ifdef LEXDEBUG
		if(debug){
			fprintf(yyout,"stopped at %d with ",lsp>yylstate?*(lsp-1)-yysvec-1:0);
			allprint(yych);
			putchar('\n');
			}
# endif
		while (lsp-- > yylstate){
			*yylastch-- = 0;
			if (*lsp != 0 && (yyfnd= (*lsp)->yystops) && *yyfnd > 0){
				yyolsp = lsp;
				if(yyextra[*yyfnd]){		/* must backup */
					while(yyback((*lsp)->yystops,-*yyfnd) != 1 && lsp > yylstate){
						lsp--;
						unput(*yylastch--);
						}
					}
				yyprevious = YYU(*yylastch);
				yylsp = lsp;
				yyleng = yylastch-(Uchar*)yytext+1;
				yytext[yyleng] = 0;
# ifdef LEXDEBUG
				if(debug){
					fprintf(yyout,"\nmatch '%s'", yytext);
					fprintf(yyout," action %d\n",*yyfnd);
					}
# endif
				return(*yyfnd++);
				}
			unput(*yylastch);
			}
		if (yytext[0] == 0  /* && feof(yyin) */)
			{
			yysptr=yysbuf;
			return(0);
			}
		yyprevious = input();
		yytext[0] = yyprevious;
		if (yyprevious>0)
			output(yyprevious);
		yylastch = (Uchar*)yytext;
# ifdef LEXDEBUG
		if(debug)putchar('\n');
# endif
		}
	}
yyback(int *p, int m)
{
if (p==0) return(0);
while (*p)
	{
	if (*p++ == m)
		return(1);
	}
return(0);
}
	/* the following are only used in the lex library */
yyinput(void){
	return(input());
}
void
yyoutput(int c)
{
	output(c);
}
void
yyunput(int c)
{
	unput(c);
}

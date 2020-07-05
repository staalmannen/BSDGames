#include <stdlib.h>

#line	54	"/usr/glenda/src/BSDgames/atc/grammar.y"
typedef union  {
	int	ival;
	char	cval;
} YYSTYPE;
#define	HeightOp	57346
#define	WidthOp	57347
#define	UpdateOp	57348
#define	NewplaneOp	57349
#define	DirOp	57350
#define	ConstOp	57351
#define	LineOp	57352
#define	AirportOp	57353
#define	BeaconOp	57354
#define	ExitOp	57355

#line	60	"/usr/glenda/src/BSDgames/atc/grammar.y"
#include "include.h"

#include <sys/cdefs.h>
#ifndef lint
#if 0
static char sccsid[] = "@(#)grammar.y	8.1 (Berkeley) 5/31/93";
#else
__RCSID("$NetBSD: grammar.y,v 1.8 2003/08/07 09:36:54 agc Exp $");
#endif
#endif /* not lint */

int	errors = 0;
int	line = 1;
extern	int	yyerrflag;
#ifndef	YYMAXDEPTH
#define	YYMAXDEPTH	150
#endif
YYSTYPE	yylval;
YYSTYPE	yyval;
#define YYEOFCODE 1
#define YYERRCODE 2

#line	285	"/usr/glenda/src/BSDgames/atc/grammar.y"


void
check_edge(x, y)
	int x, y;
{
	if (!(x == 0) && !(x == sp->width - 1) && 
	    !(y == 0) && !(y == sp->height - 1))
		yyerror("edge value not on edge.");
}

void
check_point(x, y)
	int x, y;
{
	if (x < 1 || x >= sp->width - 1)
		yyerror("X value out of range.");
	if (y < 1 || y >= sp->height - 1)
		yyerror("Y value out of range.");
}

void
check_linepoint(x, y)
	int x, y;
{
	if (x < 0 || x >= sp->width)
		yyerror("X value out of range.");
	if (y < 0 || y >= sp->height)
		yyerror("Y value out of range.");
}

void
check_line(x1, y1, x2, y2)
	int x1, y1, x2, y2;
{
	int	d1, d2;

	check_linepoint(x1, y1);
	check_linepoint(x2, y2);

	d1 = ABS(x2 - x1);
	d2 = ABS(y2 - y1);

	if (!(d1 == d2) && !(d1 == 0) && !(d2 == 0))
		yyerror("Bad line endpoints.");
}

int
yyerror(s)
	const char *s;
{
	fprintf(stderr, "\"%s\": line %d: %s\n", file, line, s);
	errors++;

	return (errors);
}

void
check_edir(x, y, dir)
	int x, y, dir;
{
	int	bad = 0;

	if (x == sp->width - 1)
		x = 2;
	else if (x != 0)
		x = 1;
	if (y == sp->height - 1)
		y = 2;
	else if (y != 0)
		y = 1;
	
	switch (x * 10 + y) {
	case 00: if (dir != 3) bad++; break;
	case 01: if (dir < 1 || dir > 3) bad++; break;
	case 02: if (dir != 1) bad++; break;
	case 10: if (dir < 3 || dir > 5) bad++; break;
	case 11: break;
	case 12: if (dir > 1 && dir < 7) bad++; break;
	case 20: if (dir != 5) bad++; break;
	case 21: if (dir < 5) bad++; break;
	case 22: if (dir != 7) bad++; break;
	default:
		yyerror("Unknown value in checkdir!  Get help!");
		break;
	}
	if (bad)
		yyerror("Bad direction for entrance at exit.");
}

int
checkdefs()
{
	int	err = 0;

	if (sp->width == 0) {
		yyerror("'width' undefined.");
		err++;
	}
	if (sp->height == 0) {
		yyerror("'height' undefined.");
		err++;
	}
	if (sp->update_secs == 0) {
		yyerror("'update' undefined.");
		err++;
	}
	if (sp->newplane_time == 0) {
		yyerror("'newplane' undefined.");
		err++;
	}
	if (err)
		return (-1);
	else
		return (0);
}
short	yyexca[] =
{-1, 1,
	1, -1,
	-2, 0,
};
#define	YYNPROD	31
#define	YYPRIVATE 57344
#define	YYLAST	76
short	yyact[] =
{
  46,  43,  40,  37,  76,  18,  45,  75,  71,  70,
  69,  65,  72,  48,  57,  42,  39,  32,  31,  30,
  29,  22,  23,  20,  21,  28,  44,  58,  55,  52,
  49,  36,  35,  34,  33,  17,  16,  15,  14,  74,
  73,  67,  50,  64,  53,  63,  56,  62,  59,  11,
  10,   8,   9,  61,  47,  60,  54,  51,  27,  26,
  25,  24,  68,  66,   2,  41,  38,  19,  13,   7,
   6,   5,   4,   3,  12,   1
};
short	yypact[] =
{
  45,-1000,-1000,  45,-1000,-1000,-1000,-1000,  24,  23,
  22,  21,  11,-1000,  52,  51,  50,  49,-1000,  11,
   4,   3,   2,   1,  19,  18,  17,  16,-1000,  -1,
  -2, -13,  -4,-1000,-1000,-1000,-1000,  15,  -1,  48,
  14,  -2,  47,  13, -13,  -3,  12,  -4,  46,-1000,
-1000,  44,-1000,-1000,  38,-1000,-1000,  36,-1000,-1000,
  34,  -7,  55,  32,  54,-1000,  -8,  -9, -10,-1000,
  -5,-1000,  31,  30, -11, -16,-1000
};
short	yypgo[] =
{
   0,  75,  64,  74,   5,  73,  72,  71,  70,  69,
  67,   3,   2,   1,   0,  66,  65,  54,  26
};
short	yyr1[] =
{
   0,   3,   1,   2,   2,   5,   5,   5,   5,   6,
   7,   9,   8,   4,   4,  10,  10,  10,  10,  11,
  11,  15,  12,  12,  16,  14,  14,  17,  13,  13,
  18
};
short	yyr2[] =
{
   0,   0,   3,   2,   1,   1,   1,   1,   1,   4,
   4,   4,   4,   2,   1,   4,   4,   4,   4,   2,
   1,   4,   2,   1,   5,   2,   1,   5,   2,   1,
  10
};
short	yychk[] =
{
-1000,  -1,  -2,  -5,  -6,  -7,  -8,  -9,   6,   7,
   5,   4,  -3,  -2,  14,  14,  14,  14,  -4, -10,
  12,  13,  10,  11,   9,   9,   9,   9,  -4,  16,
  16,  16,  16,  15,  15,  15,  15, -11, -15,  17,
 -12, -16,  17, -13, -18,  19, -14, -17,  17,  15,
 -11,   9,  15, -12,   9,  15, -13,  17,  15, -14,
   9,   9,   9,   9,   9,  18,   8,   9,   8,  18,
  18,  18,  17,   9,   9,  18,  20
};
short	yydef[] =
{
   0,  -2,   1,   4,   5,   6,   7,   8,   0,   0,
   0,   0,   0,   3,   0,   0,   0,   0,   2,  14,
   0,   0,   0,   0,   0,   0,   0,   0,  13,   0,
   0,   0,   0,   9,  10,  12,  11,   0,  20,   0,
   0,  23,   0,   0,  29,   0,   0,  26,   0,  15,
  19,   0,  16,  22,   0,  17,  28,   0,  18,  25,
   0,   0,   0,   0,   0,  21,   0,   0,   0,  24,
   0,  27,   0,   0,   0,   0,  30
};
short	yytok1[] =
{
   1,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
  17,  18,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,  16,  15,
   0,  14,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,  19,   0,  20
};
short	yytok2[] =
{
   2,   3,   4,   5,   6,   7,   8,   9,  10,  11,
  12,  13
};
long	yytok3[] =
{
   0
};

#line	1	"/sys/lib/yaccpar"
#define YYFLAG 		-1000
#define	yyclearin	yychar = -1
#define	yyerrok		yyerrflag = 0

#ifdef	yydebug
#include	"y.debug"
#else
#define	yydebug		0
char*	yytoknames[1];		/* for debugging */
char*	yystates[1];		/* for debugging */
#endif

/*	parser for yacc output	*/

int	yynerrs = 0;		/* number of errors */
int	yyerrflag = 0;		/* error recovery flag */

extern	int	fprint(int, char*, ...);
extern	int	sprint(char*, char*, ...);

char*
yytokname(int yyc)
{
	static char x[16];

	if(yyc > 0 && yyc <= sizeof(yytoknames)/sizeof(yytoknames[0]))
	if(yytoknames[yyc-1])
		return yytoknames[yyc-1];
	sprint(x, "<%d>", yyc);
	return x;
}

char*
yystatname(int yys)
{
	static char x[16];

	if(yys >= 0 && yys < sizeof(yystates)/sizeof(yystates[0]))
	if(yystates[yys])
		return yystates[yys];
	sprint(x, "<%d>\n", yys);
	return x;
}

long
yylex1(void)
{
	long yychar;
	long *t3p;
	int c;

	yychar = yylex();
	if(yychar <= 0) {
		c = yytok1[0];
		goto out;
	}
	if(yychar < sizeof(yytok1)/sizeof(yytok1[0])) {
		c = yytok1[yychar];
		goto out;
	}
	if(yychar >= YYPRIVATE)
		if(yychar < YYPRIVATE+sizeof(yytok2)/sizeof(yytok2[0])) {
			c = yytok2[yychar-YYPRIVATE];
			goto out;
		}
	for(t3p=yytok3;; t3p+=2) {
		c = t3p[0];
		if(c == yychar) {
			c = t3p[1];
			goto out;
		}
		if(c == 0)
			break;
	}
	c = 0;

out:
	if(c == 0)
		c = yytok2[1];	/* unknown char */
	if(yydebug >= 3)
		fprint(2, "lex %.4lux %s\n", yychar, yytokname(c));
	return c;
}

int
yyparse(void)
{
	struct
	{
		YYSTYPE	yyv;
		int	yys;
	} yys[YYMAXDEPTH], *yyp, *yypt;
	short *yyxi;
	int yyj, yym, yystate, yyn, yyg;
	long yychar;
	YYSTYPE save1, save2;
	int save3, save4;

	save1 = yylval;
	save2 = yyval;
	save3 = yynerrs;
	save4 = yyerrflag;

	yystate = 0;
	yychar = -1;
	yynerrs = 0;
	yyerrflag = 0;
	yyp = &yys[-1];
	goto yystack;

ret0:
	yyn = 0;
	goto ret;

ret1:
	yyn = 1;
	goto ret;

ret:
	yylval = save1;
	yyval = save2;
	yynerrs = save3;
	yyerrflag = save4;
	return yyn;

yystack:
	/* put a state and value onto the stack */
	if(yydebug >= 4)
		fprint(2, "char %s in %s", yytokname(yychar), yystatname(yystate));

	yyp++;
	if(yyp >= &yys[YYMAXDEPTH]) {
		yyerror("yacc stack overflow");
		goto ret1;
	}
	yyp->yys = yystate;
	yyp->yyv = yyval;

yynewstate:
	yyn = yypact[yystate];
	if(yyn <= YYFLAG)
		goto yydefault; /* simple state */
	if(yychar < 0)
		yychar = yylex1();
	yyn += yychar;
	if(yyn < 0 || yyn >= YYLAST)
		goto yydefault;
	yyn = yyact[yyn];
	if(yychk[yyn] == yychar) { /* valid shift */
		yychar = -1;
		yyval = yylval;
		yystate = yyn;
		if(yyerrflag > 0)
			yyerrflag--;
		goto yystack;
	}

yydefault:
	/* default state action */
	yyn = yydef[yystate];
	if(yyn == -2) {
		if(yychar < 0)
			yychar = yylex1();

		/* look through exception table */
		for(yyxi=yyexca;; yyxi+=2)
			if(yyxi[0] == -1 && yyxi[1] == yystate)
				break;
		for(yyxi += 2;; yyxi += 2) {
			yyn = yyxi[0];
			if(yyn < 0 || yyn == yychar)
				break;
		}
		yyn = yyxi[1];
		if(yyn < 0)
			goto ret0;
	}
	if(yyn == 0) {
		/* error ... attempt to resume parsing */
		switch(yyerrflag) {
		case 0:   /* brand new error */
			yyerror("syntax error");
			yynerrs++;
			if(yydebug >= 1) {
				fprint(2, "%s", yystatname(yystate));
				fprint(2, "saw %s\n", yytokname(yychar));
			}

		case 1:
		case 2: /* incompletely recovered error ... try again */
			yyerrflag = 3;

			/* find a state where "error" is a legal shift action */
			while(yyp >= yys) {
				yyn = yypact[yyp->yys] + YYERRCODE;
				if(yyn >= 0 && yyn < YYLAST) {
					yystate = yyact[yyn];  /* simulate a shift of "error" */
					if(yychk[yystate] == YYERRCODE)
						goto yystack;
				}

				/* the current yyp has no shift onn "error", pop stack */
				if(yydebug >= 2)
					fprint(2, "error recovery pops state %d, uncovers %d\n",
						yyp->yys, (yyp-1)->yys );
				yyp--;
			}
			/* there is no state on the stack with an error shift ... abort */
			goto ret1;

		case 3:  /* no shift yet; clobber input char */
			if(yydebug >= 2)
				fprint(2, "error recovery discards %s\n", yytokname(yychar));
			if(yychar == YYEOFCODE)
				goto ret1;
			yychar = -1;
			goto yynewstate;   /* try again in the same state */
		}
	}

	/* reduction by production yyn */
	if(yydebug >= 2)
		fprint(2, "reduce %d in:\n\t%s", yyn, yystatname(yystate));

	yypt = yyp;
	yyp -= yyr2[yyn];
	yyval = (yyp+1)->yyv;
	yym = yyn;

	/* consult goto table to find next state */
	yyn = yyr1[yyn];
	yyg = yypgo[yyn];
	yyj = yyg + yyp->yys + 1;

	if(yyj >= YYLAST || yychk[yystate=yyact[yyj]] != -yyn)
		yystate = yyact[yyg];
	switch(yym) {
		
case 1:
#line	77	"/usr/glenda/src/BSDgames/atc/grammar.y"
{ if (checkdefs() < 0) return (errors); } break;
case 2:
#line	78	"/usr/glenda/src/BSDgames/atc/grammar.y"
{ 
		if (sp->num_exits + sp->num_airports < 2)
			yyerror("Need at least 2 airports and/or exits.");
		return (errors);
		} break;
case 9:
#line	99	"/usr/glenda/src/BSDgames/atc/grammar.y"
{
		if (sp->update_secs != 0)
			return (yyerror("Redefinition of 'update'."));
		else if (yypt[-1].yyv.ival < 1)
			return (yyerror("'update' is too small."));
		else
			sp->update_secs = yypt[-1].yyv.ival;
		} break;
case 10:
#line	111	"/usr/glenda/src/BSDgames/atc/grammar.y"
{
		if (sp->newplane_time != 0)
			return (yyerror("Redefinition of 'newplane'."));
		else if (yypt[-1].yyv.ival < 1)
			return (yyerror("'newplane' is too small."));
		else
			sp->newplane_time = yypt[-1].yyv.ival;
		} break;
case 11:
#line	123	"/usr/glenda/src/BSDgames/atc/grammar.y"
{
		if (sp->height != 0)
			return (yyerror("Redefinition of 'height'."));
		else if (yypt[-1].yyv.ival < 3)
			return (yyerror("'height' is too small."));
		else
			sp->height = yypt[-1].yyv.ival; 
		} break;
case 12:
#line	135	"/usr/glenda/src/BSDgames/atc/grammar.y"
{
		if (sp->width != 0)
			return (yyerror("Redefinition of 'width'."));
		else if (yypt[-1].yyv.ival < 3)
			return (yyerror("'width' is too small."));
		else
			sp->width = yypt[-1].yyv.ival; 
		} break;
case 13:
#line	147	"/usr/glenda/src/BSDgames/atc/grammar.y"
{} break;
case 14:
#line	149	"/usr/glenda/src/BSDgames/atc/grammar.y"
{} break;
case 15:
#line	154	"/usr/glenda/src/BSDgames/atc/grammar.y"
{} break;
case 16:
#line	156	"/usr/glenda/src/BSDgames/atc/grammar.y"
{} break;
case 17:
#line	158	"/usr/glenda/src/BSDgames/atc/grammar.y"
{} break;
case 18:
#line	160	"/usr/glenda/src/BSDgames/atc/grammar.y"
{} break;
case 19:
#line	165	"/usr/glenda/src/BSDgames/atc/grammar.y"
{} break;
case 20:
#line	167	"/usr/glenda/src/BSDgames/atc/grammar.y"
{} break;
case 21:
#line	172	"/usr/glenda/src/BSDgames/atc/grammar.y"
{
		if (sp->num_beacons % REALLOC == 0) {
			if (sp->beacon == NULL)
				sp->beacon = (BEACON *) malloc((sp->num_beacons
					+ REALLOC) * sizeof (BEACON));
			else
				sp->beacon = (BEACON *) realloc(sp->beacon,
					(sp->num_beacons + REALLOC) * 
					sizeof (BEACON));
			if (sp->beacon == NULL)
				return (yyerror("No memory available."));
		}
		sp->beacon[sp->num_beacons].x = yypt[-2].yyv.ival;
		sp->beacon[sp->num_beacons].y = yypt[-1].yyv.ival;
		check_point(yypt[-2].yyv.ival, yypt[-1].yyv.ival);
		sp->num_beacons++;
		} break;
case 22:
#line	193	"/usr/glenda/src/BSDgames/atc/grammar.y"
{} break;
case 23:
#line	195	"/usr/glenda/src/BSDgames/atc/grammar.y"
{} break;
case 24:
#line	200	"/usr/glenda/src/BSDgames/atc/grammar.y"
{
		int	dir;

		if (sp->num_exits % REALLOC == 0) {
			if (sp->exit == NULL)
				sp->exit = (EXIT *) malloc((sp->num_exits + 
					REALLOC) * sizeof (EXIT));
			else
				sp->exit = (EXIT *) realloc(sp->exit,
					(sp->num_exits + REALLOC) * 
					sizeof (EXIT));
			if (sp->exit == NULL)
				return (yyerror("No memory available."));
		}
		dir = dir_no(yypt[-1].yyv.cval);
		sp->exit[sp->num_exits].x = yypt[-3].yyv.ival;
		sp->exit[sp->num_exits].y = yypt[-2].yyv.ival;
		sp->exit[sp->num_exits].dir = dir;
		check_edge(yypt[-3].yyv.ival, yypt[-2].yyv.ival);
		check_edir(yypt[-3].yyv.ival, yypt[-2].yyv.ival, dir);
		sp->num_exits++;
		} break;
case 25:
#line	226	"/usr/glenda/src/BSDgames/atc/grammar.y"
{} break;
case 26:
#line	228	"/usr/glenda/src/BSDgames/atc/grammar.y"
{} break;
case 27:
#line	233	"/usr/glenda/src/BSDgames/atc/grammar.y"
{
		int	dir;

		if (sp->num_airports % REALLOC == 0) {
			if (sp->airport == NULL)
				sp->airport=(AIRPORT *)malloc((sp->num_airports
					+ REALLOC) * sizeof(AIRPORT));
			else
				sp->airport = (AIRPORT *) realloc(sp->airport,
					(sp->num_airports + REALLOC) * 
					sizeof(AIRPORT));
			if (sp->airport == NULL)
				return (yyerror("No memory available."));
		}
		dir = dir_no(yypt[-1].yyv.cval);
		sp->airport[sp->num_airports].x = yypt[-3].yyv.ival;
		sp->airport[sp->num_airports].y = yypt[-2].yyv.ival;
		sp->airport[sp->num_airports].dir = dir;
		check_point(yypt[-3].yyv.ival, yypt[-2].yyv.ival);
		sp->num_airports++;
		} break;
case 28:
#line	258	"/usr/glenda/src/BSDgames/atc/grammar.y"
{} break;
case 29:
#line	260	"/usr/glenda/src/BSDgames/atc/grammar.y"
{} break;
case 30:
#line	265	"/usr/glenda/src/BSDgames/atc/grammar.y"
{
		if (sp->num_lines % REALLOC == 0) {
			if (sp->line == NULL)
				sp->line = (LINE *) malloc((sp->num_lines + 
					REALLOC) * sizeof (LINE));
			else
				sp->line = (LINE *) realloc(sp->line,
					(sp->num_lines + REALLOC) *
					sizeof (LINE));
			if (sp->line == NULL)
				return (yyerror("No memory available."));
		}
		sp->line[sp->num_lines].p1.x = yypt[-7].yyv.ival;
		sp->line[sp->num_lines].p1.y = yypt[-6].yyv.ival;
		sp->line[sp->num_lines].p2.x = yypt[-3].yyv.ival;
		sp->line[sp->num_lines].p2.y = yypt[-2].yyv.ival;
		check_line(yypt[-7].yyv.ival, yypt[-6].yyv.ival, yypt[-3].yyv.ival, yypt[-2].yyv.ival);
		sp->num_lines++;
		} break;
	}
	goto yystack;  /* stack new state and value */
}

%error-verbose
%locations
%{
#include <iostream>
#include "stdio.h"
#include "block.h"
#include "exp.h"
#include "stat.h"

extern char *yytext;
extern int lines;

extern "C" {
	extern int yylex();
	void yyerror(const char *s);
	int yyparse (void);
}

struct Block *finalBlock;

struct Standard {
	int line;
	int id;
}

%}

%union {   
	   const char *str;

	   struct Standard standard;

	   struct Block *pBlock;
	   struct Stat *pStat;
	   struct Exp *pExp;

	   struct NameList *pNameList;
	   struct ExpList *pExpList;
	   struct StatList *pStatList;

	   struct IfStat *pIfStat;
	   struct FuncDefExp *pFuncDefExp;
	   struct FuncCallExp *pFuncCallExp;
	   struct FieldExp *pFieldExp;
};


%token	TOKEN_EOF         		           0	// end-of-file
%token	standard>TOKEN_VARARG                       1	// ...
%token	TOKEN_SEP_SEMI                     2	// ;
%token	TOKEN_SEP_COMMA                    3	// ,
%token	TOKEN_SEP_DOT                      4	// .
%token	TOKEN_SEP_COLON                    5	// :
%token	TOKEN_SEP_LABEL                    6	// ::
%token	TOKEN_SEP_LPAREN                   7	// (
%token	TOKEN_SEP_RPAREN                   8	// )
%token	TOKEN_SEP_LBRACK                   9	// [
%token	TOKEN_SEP_RBRACK                   10	// ]
%token	TOKEN_SEP_LCURLY                   11	// {
%token	TOKEN_SEP_RCURLY                   12	// }
%token	TOKEN_OP_ASSIGN                    13	// =
%token	TOKEN_OP_MINUS                     14	// - (sub or unm)
%token	TOKEN_OP_WAVE                      15	// ~ (bnot or bxor)
%token	TOKEN_OP_ADD                       16	// +
%token	TOKEN_OP_MUL                       17	// *
%token	TOKEN_OP_DIV                       18	// /
%token	TOKEN_OP_IDIV                      19	// //
%token	TOKEN_OP_POW                       20	// ^
%token	TOKEN_OP_MOD                       21	// %
%token	TOKEN_OP_BAND                      22	// &
%token	TOKEN_OP_BOR                       23	// |
%token	TOKEN_OP_SHR                       24	// >>
%token	TOKEN_OP_SHL                       25	// <<
%token	TOKEN_OP_CONCAT                    26	// ..
%token	TOKEN_OP_LT                        27	// <
%token	TOKEN_OP_LE                        28	// <=
%token	TOKEN_OP_GT                        29	// >
%token	TOKEN_OP_GE                        30	// >=
%token	TOKEN_OP_EQ                        31	// ==
%token	TOKEN_OP_NE                        32	// ~=
%token	TOKEN_OP_LEN                       33	// #
%token	TOKEN_OP_AND                       34	// and
%token	TOKEN_OP_OR                        35	// or
%token	TOKEN_OP_NOT                       36	// not
%token	TOKEN_KW_BREAK                     37	// break
%token	TOKEN_KW_DO                        38	// do
%token	TOKEN_KW_ELSE                      39	// else
%token	TOKEN_KW_ELSEIF                    40	// elseif
%token	TOKEN_KW_END                       41	// end
%token	TOKEN_KW_FALSE                     42	// false
%token	TOKEN_KW_FOR                       43	// for
%token	TOKEN_KW_FUNCTION                  44	// function
%token	TOKEN_KW_GOTO                      45	// goto
%token	TOKEN_KW_IF                        46	// if
%token	TOKEN_KW_IN                        47	// in
%token	TOKEN_KW_LOCAL                     48	// local
%token	TOKEN_KW_NIL                       49	// nil
%token	TOKEN_KW_REPEAT                    50	// repeat
%token	TOKEN_KW_RETURN                    51	// return
%token	TOKEN_KW_THEN                      52	// then
%token	TOKEN_KW_TRUE                      53	// true
%token	TOKEN_KW_UNTIL                     54	// until
%token	TOKEN_KW_WHILE                     55	// while
%token	TOKEN_IDENTIFIER                   56	// identifier
%token	TOKEN_NUMBER                       57	// number literal
%token	TOKEN_STRING                       58	// string literal
%token  TOKEN_OP_UNM 	// TOKEN_OP_MINUS
%token  TOKEN_OP_SUB 	// TOKEN_OP_MINUS
%token  TOKEN_OP_BNOT 	// TOKEN_OP_WAVE
%token  TOKEN_OP_BXOR 	// TOKEN_OP_WAVE
%token	TOKEN_COMMAVARARG                  59	// , ...

%type<str> name label

%type<pBlock> block
%type<pStat> stat ifstat
%type<pExp> var prefixexp tableconstructor
%type<pExp> exp exp12 exp11 exp10 exp9 exp8 exp7 exp6 exp5 exp4 exp2l exp2 exp1 exp0

%type<pNameList> namelist parlist
%type<pStatList> stats
%type<pExpList> retstat explist args varlist fieldlist

%type<pIfStat> eifstats
%type<pFuncDefExp> funcbody
%type<pFuncCallExp> functioncall
%type<pFieldExp> field

%%

block : stats retstat 	{$$ = new Block(); $$->lastline = lines; $$->stats = $1->stats; $$->retExps = $2->exps; finalBlock = $$;}
	  | stats 			{$$ = new Block(); $$->lastline = lines; $$->stats.push_back($1); finalBlock = $$;}
	  | retstat 		{$$ = new Block(); $$->lastline = lines; $$->retExps = $1->exps; finalBlock = $$;}
	  | 				{$$ = new Block(); $$->lastline = lines; finalBlock = $$;}
	  ;

stats : stat stats 		{$2->stats.push_back($1); $$ = $2;}
      | stat       		{$$ = new StatList(); $$->stats.push_back($1);}
      ;


stat  : TOKEN_SEP_SEMI										{$$ = new Stat();}
	  | TOKEN_KW_BREAK										{auto t = new BreakStat(); t->line = lines; $$ = t;}
	  | label 												{auto t = new LabelStat(); t->name = $1; $$ = t;}
	  | TOKEN_KW_GOTO name   								{auto t = new GotoStat(); t->name = $2; $$ = t;}
	  | TOKEN_KW_DO block TOKEN_KW_END						{auto t = new DoStat(); t->block = $2; $$ = t;}
	  | TOKEN_KW_WHILE exp TOKEN_KW_DO block TOKEN_KW_END	{auto t = new WhileStat(); t->exp = $2; t->block = $4; $$ = t;}
	  | TOKEN_KW_REPEAT block TOKEN_KW_UNTIL exp 			{auto t = new RepeatStat(); t->block = $2; t->exp = $4; $$ = t;}
	  | TOKEN_KW_FOR name TOKEN_OP_ASSIGN exp TOKEN_SEP_COMMA exp TOKEN_KW_DO block TOKEN_KW_END						
	  {auto t = new ForNumStat(); t->varName = $2; t->initExp = $4; t->limitEXp = $6; t->stepExp = new IntegerExp(lines, 1); t->block = $8; $$ = t;}
	  | TOKEN_KW_FOR name TOKEN_OP_ASSIGN exp TOKEN_SEP_COMMA exp TOKEN_SEP_COMMA exp TOKEN_KW_DO block TOKEN_KW_END	
	  {auto t = new ForNumStat(); t->varName = $2; t->initExp = $4; t->limitEXp = $6; t->stepExp = $8; t->block = $10; $$ = t;}
	  | TOKEN_KW_FOR namelist TOKEN_KW_IN explist TOKEN_KW_DO block TOKEN_KW_END	{auto t = new ForInStat(); t->nameList = $2->names; t->expList = $4->exps; t->block = $6; $$ = t;}
	  | TOKEN_KW_FUNCTION funcname funcbody											{$$ = new Stat();}
	  | TOKEN_KW_LOCAL TOKEN_KW_FUNCTION name funcbody								{auto t = new LocalFuncDefStat(); t->name = $3; t->defExp = $4; $$ = t;}
	  | TOKEN_KW_LOCAL namelist TOKEN_OP_ASSIGN explist								{auto t = new LocalVarDeclStat(); t->nameList = $2->names; t->expList = $4->exps; $$ = t;}
	  | varlist TOKEN_OP_ASSIGN explist												{auto t = new AssignStat(); t->varList = $1->exps; t->expList = $3->exps; $$ = t;}
	  | ifstat 												{$$ = $1;}
	  | functioncall										{auto t = new FuncCallStat(); t->funcCallEXp = $1; $$ = t;}
	  ;

label : TOKEN_SEP_LABEL name TOKEN_SEP_LABEL				{$$ = $2;}
	  ;

ifstat : TOKEN_KW_IF exp TOKEN_KW_THEN block TOKEN_KW_END									{auto t = new IfStat(); t->exps.push_back($2); t->blocks.push_back($4); $$ = t;}
	   | TOKEN_KW_IF exp TOKEN_KW_THEN block TOKEN_KW_ELSE block TOKEN_KW_END				{auto t = new IfStat(); t->exps.push_back($2); t->blocks.push_back($4); t->blocks.push_back($6); $$ = t;}
	   | TOKEN_KW_IF exp TOKEN_KW_THEN block eifstats TOKEN_KW_END							{$5->exps.push_back($2); $5->blocks.push_back($4); $$ = $5;}
	   | TOKEN_KW_IF exp TOKEN_KW_THEN block eifstats TOKEN_KW_ELSE block TOKEN_KW_END		{$5->exps.push_back($2); $5->blocks.push_back($4); $5->blocks.push_back($7); $$ = $5;}
	   ;

eifstats : TOKEN_KW_ELSEIF exp TOKEN_KW_THEN block eifstats		{$5->exps.push_back($2); $5->blocks.push_back($4); $$ = $5;}
		 | TOKEN_KW_ELSEIF exp TOKEN_KW_THEN block 				{auto t = new IfStat(); t->exps.push_back($2); t->blocks.push_back($4); $$ = t;}
		 ;

functiondef : TOKEN_KW_FUNCTION funcbody
			;

funcbody : TOKEN_SEP_LPAREN parlist TOKEN_SEP_RPAREN block TOKEN_KW_END		{$$ = new FuncDefExp(); $$->parlist = $2->names; $$->block = $4;}
		 | TOKEN_SEP_LPAREN TOKEN_SEP_RPAREN block TOKEN_KW_END  			{$$ = new FuncDefExp(); $$->block = $3;}
		 ;

funcname : pointName TOKEN_SEP_COLON name
		 | pointName
		 ;

pointName : name TOKEN_SEP_DOT pointName
		  | name
		  ;

parlist : namelist TOKEN_COMMAVARARG				{$$ = $1; $$->names.push_back("...");}
		| namelist 									{$$ = $1;}
		| TOKEN_VARARG 								{$$ = new NameList(); $$->names.push_back("...");}
		;


retstat : TOKEN_KW_RETURN explist TOKEN_SEP_SEMI	{$$ = $2;}
		| TOKEN_KW_RETURN TOKEN_SEP_SEMI			{$$ = new ExpList();}
		| TOKEN_KW_RETURN							{$$ = new ExpList();}
	    ;

explist : exp TOKEN_SEP_COMMA explist				{$3->exps.push_back($1); $$ = $3;}
		| exp 										{$$ = new ExpList(); $$->exps.push_back($1);}
		;

namelist : name TOKEN_SEP_COMMA namelist 			{$3->names.push_back($1); $$ = $3;}
		 | name 									{$$ = new NameList(); $$->names.push_back($1);}
		 ;

varlist : var TOKEN_SEP_COMMA varlist  				{$3->exps.push_back($1); $$ = $3;}
		| var 										{$$ = new ExpList(); $$->exps.push_back($1);}
		;

functioncall : prefixexp args 						{$$ = new FuncCallExp(); $$->prefixExp = $1; $$->args = $2->exps;}
			 | prefixexp TOKEN_SEP_COLON name args  {$$ = new FuncCallExp(); $$->prefixExp = $1; $$->nameExp = new StringExp(lines, $3); $$->args = $4->exps;}
			 ;

args : TOKEN_SEP_LPAREN TOKEN_SEP_RPAREN 			{$$ = new ExpList();}
	 | TOKEN_SEP_LPAREN explist TOKEN_SEP_RPAREN 	{$$ = new ExpList(); $$->exps = $2->exps;}
	 | tableconstructor 							{$$ = new ExpList(); $$->exps.push_back($1);}
	 | TOKEN_STRING 								{$$ = new ExpList(); $$->exps.push_back(new StringExp(lines, yytext));}
	 ;

var : name 												 {$$ = new NameExp(lines, $1);}	
	| prefixexp TOKEN_SEP_LBRACK exp TOKEN_SEP_RBRACK	 {auto t = new TableAccessExp(); t->prefixExp = $1; t->keyExp = $3; $$ = t;}
	| prefixexp TOKEN_SEP_DOT name 						 {auto t = new TableAccessExp(); t->prefixExp = $1; t->keyExp = new NameExp(lines, $3); $$ = t;}
	;

prefixexp : var 										 {$$ = $1;}
		  | functioncall 								 {$$ = $1;}
		  | TOKEN_SEP_LPAREN exp TOKEN_SEP_RPAREN 	 	 {auto t = new ParensExp(); t->exp = $2; $$ = t;}
		  ;

tableconstructor : TOKEN_SEP_LCURLY fieldlist TOKEN_SEP_RCURLY		{auto t = new TableConstructorExp(); t->fieldExps = $2->exps; $$ = t;}
				 | TOKEN_SEP_LCURLY TOKEN_SEP_RCURLY 	 			{$$ = new TableConstructorExp();}
				 ;

fieldlist : field fieldsep fieldlist 								{$3->exps.push_back($1); $$ = $3;}
		  | field 													{$$ = new ExpList(); $$->exps.push_back($1);}
		  ;

field : TOKEN_SEP_LBRACK exp TOKEN_SEP_RBRACK TOKEN_OP_ASSIGN exp 	{$$ = new FieldExp(); $$->keyExp = $2; $$->valExp = $5;}
	  | name TOKEN_OP_ASSIGN exp 									{$$ = new FieldExp(); $$->keyExp = new NameExp(lines, $1); $$->valExp = $3;}
	  | exp 														{$$ = new FieldExp(); $$->keyExp = nullptr; $$->valExp = $1;}
	  ;

fieldsep : TOKEN_SEP_COMMA
		 | TOKEN_SEP_SEMI
		 ;

name : TOKEN_IDENTIFIER				{$$ = yytext;}
	 ;

exp  : exp12						{$$ = new Exp();}
	 ;

exp12 : exp11 TOKEN_OP_OR exp12		{$$ = new Exp();}
	  | exp11						{$$ = new Exp();}
	  ;

exp11 : exp10 TOKEN_OP_AND exp11	{$$ = new Exp();}
	  | exp10						{$$ = new Exp();}
	  ;

exp10 : exp9 TOKEN_OP_LT exp10		{$$ = new Exp();}
	  | exp9 TOKEN_OP_LE exp10		{$$ = new Exp();}
	  | exp9 TOKEN_OP_GT exp10		{$$ = new Exp();}
	  | exp9 TOKEN_OP_GE exp10		{$$ = new Exp();}
	  | exp9 TOKEN_OP_EQ exp10		{$$ = new Exp();}
	  | exp9 TOKEN_OP_NE exp10		{$$ = new Exp();}
	  | exp9						{$$ = new Exp();}
	  ;

exp9 : exp8 TOKEN_OP_BOR exp9		{$$ = new Exp();}
     | exp8	{$$ = new Exp();}
     ;


exp8 : exp7 TOKEN_OP_WAVE exp8		{$$ = new Exp();}
     | exp7	{$$ = new Exp();}
     ;

exp7 : exp6 TOKEN_OP_BAND exp7		{$$ = new Exp();}
     | exp6	{$$ = new Exp();}
     ;

exp6 : exp5 TOKEN_OP_SHL exp6		{$$ = new Exp();}
     | exp5 TOKEN_OP_SHR exp6		{$$ = new Exp();}
     | exp5	{$$ = new Exp();}
     ;

exp5 : exp4 TOKEN_OP_CONCAT exp5	{$$ = new Exp();}
     | exp4							{$$ = new Exp();}
     ;

exp4 : exp2 TOKEN_OP_MINUS exp4		{$$ = new Exp();}
     | exp2 TOKEN_OP_ADD exp4		{$$ = new Exp();}
     | exp2 TOKEN_OP_MUL exp4		{$$ = new Exp();}
     | exp2 TOKEN_OP_DIV exp4		{$$ = new Exp();}
     | exp2 TOKEN_OP_IDIV exp4		{$$ = new Exp();}
     | exp2 TOKEN_OP_MOD exp4 		{$$ = new Exp();}
     | exp2 						{$$ = new Exp();}
     ;

exp2 : TOKEN_OP_MINUS exp1 			{$$ = new Exp();}
	 | TOKEN_OP_WAVE exp1 			{$$ = new Exp();}
	 | TOKEN_OP_LEN exp1 			{$$ = new Exp();}
	 | TOKEN_OP_NOT exp1 			{$$ = new Exp();}
	 ;

exp2l : TOKEN_OP_POW exp2 			{$$ = new Exp();}
 	  ;

exp1 : exp0 exp2l					{$$ = new Exp();}
     | exp0 						{$$ = new Exp();}
	 ;

exp0 : TOKEN_KW_NIL 				{$$ = new Exp();}
	 | TOKEN_KW_FALSE				{$$ = new Exp();}
	 | TOKEN_KW_TRUE				{$$ = new Exp();}
	 | TOKEN_NUMBER					{$$ = new Exp();}
	 | TOKEN_STRING					{$$ = new Exp();}
	 | TOKEN_VARARG 				{$$ = new Exp();}
	 | functiondef					{$$ = new Exp();}
	 | prefixexp					{$$ = new Exp();}
	 | tableconstructor				{$$ = new Exp();}
	 ;

%%

#include "lex.yy.c"

extern FILE *yyin;

int main(int argc, char *argv[]){
	yyin = stdin;

	yyparse();

	printf("%d\n", finalBlock->lastline);

	return 0;
}

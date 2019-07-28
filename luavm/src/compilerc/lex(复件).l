%{
#define	TOKEN_EOF         		           0	// end-of-file
#define	TOKEN_VARARG                       1	// ...
#define	TOKEN_SEP_SEMI                     2	// ;
#define	TOKEN_SEP_COMMA                    3	// ,
#define	TOKEN_SEP_DOT                      4	// .
#define	TOKEN_SEP_COLON                    5	// :
#define	TOKEN_SEP_LABEL                    6	// ::
#define	TOKEN_SEP_LPAREN                   7	// (
#define	TOKEN_SEP_RPAREN                   8	// )
#define	TOKEN_SEP_LBRACK                   9	// [
#define	TOKEN_SEP_RBRACK                   10	// ]
#define	TOKEN_SEP_LCURLY                   11	// {
#define	TOKEN_SEP_RCURLY                   12	// }
#define	TOKEN_OP_ASSIGN                    13	// =
#define	TOKEN_OP_MINUS                     14	// - (sub or unm)
#define	TOKEN_OP_WAVE                      15	// ~ (bnot or bxor)
#define	TOKEN_OP_ADD                       16	// +
#define	TOKEN_OP_MUL                       17	// *
#define	TOKEN_OP_DIV                       18	// /
#define	TOKEN_OP_IDIV                      19	// //
#define	TOKEN_OP_POW                       20	// ^
#define	TOKEN_OP_MOD                       21	// %
#define	TOKEN_OP_BAND                      22	// &
#define	TOKEN_OP_BOR                       23	// |
#define	TOKEN_OP_SHR                       24	// >>
#define	TOKEN_OP_SHL                       25	// <<
#define	TOKEN_OP_CONCAT                    26	// ..
#define	TOKEN_OP_LT                        27	// <
#define	TOKEN_OP_LE                        28	// <=
#define	TOKEN_OP_GT                        29	// >
#define	TOKEN_OP_GE                        30	// >=
#define	TOKEN_OP_EQ                        31	// ==
#define	TOKEN_OP_NE                        32	// ~=
#define	TOKEN_OP_LEN                       33	// #
#define	TOKEN_OP_AND                       34	// and
#define	TOKEN_OP_OR                        35	// or
#define	TOKEN_OP_NOT                       36	// not
#define	TOKEN_KW_BREAK                     37	// break
#define	TOKEN_KW_DO                        38	// do
#define	TOKEN_KW_ELSE                      39	// else
#define	TOKEN_KW_ELSEIF                    40	// elseif
#define	TOKEN_KW_END                       41	// end
#define	TOKEN_KW_FALSE                     42	// false
#define	TOKEN_KW_FOR                       43	// for
#define	TOKEN_KW_FUNCTION                  44	// function
#define	TOKEN_KW_GOTO                      45	// goto
#define	TOKEN_KW_IF                        46	// if
#define	TOKEN_KW_IN                        47	// in
#define	TOKEN_KW_LOCAL                     48	// local
#define	TOKEN_KW_NIL                       49	// nil
#define	TOKEN_KW_REPEAT                    50	// repeat
#define	TOKEN_KW_RETURN                    51	// return
#define	TOKEN_KW_THEN                      52	// then
#define	TOKEN_KW_TRUE                      53	// true
#define	TOKEN_KW_UNTIL                     54	// until
#define	TOKEN_KW_WHILE                     55	// while
#define	TOKEN_IDENTIFIER                   56	// identifier
#define	TOKEN_NUMBER                       57	// number literal
#define	TOKEN_STRING                       58	// string literal
#define TOKEN_OP_UNM TOKEN_OP_MINUS
#define TOKEN_OP_SUB TOKEN_OP_MINUS
#define TOKEN_OP_BNOT TOKEN_OP_WAVE
#define TOKEN_OP_BXOR TOKEN_OP_WAVE
int lines = 1;
%}

ws [ \t]+
windowsLine [\r][\n]
unixLine [\n]
macLine [\r]
luaLine {windowsLine}|{unixLine}|{macLine}

letter  [A-Za-z]
digit	[0-9]
identifier (_|{letter})(_|{letter}|{digit})*
number {digit}*(\.{digit}+)?([Ee][+-]?{digit}+)?
string ["]({letter}|{digit}|[ ])*["]

%%

{luaLine}       {lines++;}

and      {return(TOKEN_OP_AND);}
break    {return(TOKEN_KW_BREAK);}
do       {return(TOKEN_KW_DO);}
else     {return(TOKEN_KW_ELSE);}
elseif   {return(TOKEN_KW_ELSEIF);}
end      {return(TOKEN_KW_END);}
false    {return(TOKEN_KW_FALSE);}
for      {return(TOKEN_KW_FOR);}
function {return(TOKEN_KW_FUNCTION);}
goto     {return(TOKEN_KW_GOTO);}
if       {return(TOKEN_KW_IF);}
in       {return(TOKEN_KW_IN);}
local    {return(TOKEN_KW_LOCAL);}
nil      {return(TOKEN_KW_NIL);}
not      {return(TOKEN_OP_NOT);}
or       {return(TOKEN_OP_OR);}
repeat   {return(TOKEN_KW_REPEAT);}
return   {return(TOKEN_KW_RETURN);}
then     {return(TOKEN_KW_THEN);}
true     {return(TOKEN_KW_TRUE);}
until    {return(TOKEN_KW_UNTIL);}
while    {return(TOKEN_KW_WHILE);}

";"		 {return(TOKEN_SEP_SEMI);}
","		 {return(TOKEN_SEP_SEMI);}
"("		 {return(TOKEN_SEP_LPAREN);}
")"		 {return(TOKEN_SEP_RPAREN);}
"]"		 {return(TOKEN_SEP_RBRACK);}
"{"		 {return(TOKEN_SEP_LCURLY);}
"}"		 {return(TOKEN_SEP_RCURLY);}
"+"		 {return(TOKEN_OP_ADD);}
"-"		 {return(TOKEN_OP_MINUS);}
"*"		 {return(TOKEN_OP_MUL);}
"^"		 {return(TOKEN_OP_POW);}
"%"		 {return(TOKEN_OP_MOD);}
"&"		 {return(TOKEN_OP_BAND);}
"|"		 {return(TOKEN_OP_BOR);}
"#"		 {return(TOKEN_OP_LEN);}
"::"     {return(TOKEN_SEP_LABEL);}
":"		 {return(TOKEN_SEP_COLON);}
"//"	 {return(TOKEN_OP_IDIV);}
"/"		 {return(TOKEN_OP_DIV);}
"~="	 {return(TOKEN_OP_IDIV);}
"~"		 {return(TOKEN_OP_WAVE);}
"=="	 {return(TOKEN_OP_EQ);}
"="		 {return(TOKEN_OP_ASSIGN);}
"<<"	 {return(TOKEN_OP_SHL);}
"<="	 {return(TOKEN_OP_LE);}
"<"		 {return(TOKEN_OP_LT);}
">>"	 {return(TOKEN_OP_SHR);}
">="	 {return(TOKEN_OP_GE);}
">"		 {return(TOKEN_OP_GT);}
"..."	 {return(TOKEN_VARARG);}
".."	 {return(TOKEN_OP_CONCAT);}
"."		 {return(TOKEN_SEP_DOT);}

{ws}	 	 {/* no action */}
{string} 	 {return(TOKEN_STRING);}
{identifier} {return(TOKEN_IDENTIFIER);}
{number} 	 {return(TOKEN_NUMBER);}

%%

/*
main(int argc, char **argv)
{
	int t = yylex();

	while(t != 0){
		   
		printf("%d %d %s\n", lines, t, yytext);

    	t = yylex();
	}


    printf("%d %d EOF\n", lines, t);
}
*/
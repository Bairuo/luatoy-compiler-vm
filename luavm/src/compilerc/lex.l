%{

extern "C" {
	int yywrap(void);
	int yylex(void);
}

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

cv [,]{ws}[\.][\.][\.]

%%

{luaLine}       {lines++;}

and      {yylval.standard = new Standard(lines, TOKEN_OP_AND); return(TOKEN_OP_AND);}
break    {yylval.standard = new Standard(lines, TOKEN_KW_BREAK); return(TOKEN_KW_BREAK);}
do       {yylval.standard = new Standard(lines, TOKEN_KW_DO); return(TOKEN_KW_DO);}
else     {yylval.standard = new Standard(lines, TOKEN_KW_ELSE); return(TOKEN_KW_ELSE);}
elseif   {yylval.standard = new Standard(lines, TOKEN_KW_ELSEIF); return(TOKEN_KW_ELSEIF);}
end      {yylval.standard = new Standard(lines, TOKEN_KW_END); return(TOKEN_KW_END);}
false    {yylval.standard = new Standard(lines, TOKEN_KW_FALSE); return(TOKEN_KW_FALSE);}
for      {yylval.standard = new Standard(lines, TOKEN_KW_FOR); return(TOKEN_KW_FOR);}
function {yylval.standard = new Standard(lines, TOKEN_KW_FUNCTION); return(TOKEN_KW_FUNCTION);}
goto     {yylval.standard = new Standard(lines, TOKEN_KW_GOTO); return(TOKEN_KW_GOTO);}
if       {yylval.standard = new Standard(lines, TOKEN_KW_IF); return(TOKEN_KW_IF);}
in       {yylval.standard = new Standard(lines, TOKEN_KW_IN); return(TOKEN_KW_IN);}
local    {yylval.standard = new Standard(lines, TOKEN_KW_LOCAL); return(TOKEN_KW_LOCAL);}
nil      {yylval.standard = new Standard(lines, TOKEN_KW_NIL); return(TOKEN_KW_NIL);}
not      {yylval.standard = new Standard(lines, TOKEN_OP_NOT); return(TOKEN_OP_NOT);}
or       {yylval.standard = new Standard(lines, TOKEN_OP_OR); return(TOKEN_OP_OR);}
repeat   {yylval.standard = new Standard(lines, TOKEN_KW_REPEAT); return(TOKEN_KW_REPEAT);}
return   {yylval.standard = new Standard(lines, TOKEN_KW_RETURN); return(TOKEN_KW_RETURN);}
then     {yylval.standard = new Standard(lines, TOKEN_KW_THEN); return(TOKEN_KW_THEN);}
true     {yylval.standard = new Standard(lines, TOKEN_KW_TRUE); return(TOKEN_KW_TRUE);}
until    {yylval.standard = new Standard(lines, TOKEN_KW_UNTIL); return(TOKEN_KW_UNTIL);}
while    {yylval.standard = new Standard(lines, TOKEN_KW_WHILE); return(TOKEN_KW_WHILE);}

";"		 {yylval.standard = new Standard(lines, TOKEN_SEP_SEMI); return(TOKEN_SEP_SEMI);}
","		 {yylval.standard = new Standard(lines, TOKEN_SEP_COMMA); return(TOKEN_SEP_COMMA);}
"("		 {yylval.standard = new Standard(lines, TOKEN_SEP_LPAREN); return(TOKEN_SEP_LPAREN);}
")"		 {yylval.standard = new Standard(lines, TOKEN_SEP_RPAREN); return(TOKEN_SEP_RPAREN);}
"]"		 {yylval.standard = new Standard(lines, TOKEN_SEP_RBRACK); return(TOKEN_SEP_RBRACK);}
"["		 {yylval.standard = new Standard(lines, TOKEN_SEP_LBRACK); return(TOKEN_SEP_LBRACK);}
"{"		 {yylval.standard = new Standard(lines, TOKEN_SEP_LCURLY); return(TOKEN_SEP_LCURLY);}
"}"		 {yylval.standard = new Standard(lines, TOKEN_SEP_RCURLY); return(TOKEN_SEP_RCURLY);}
"+"		 {yylval.standard = new Standard(lines, TOKEN_OP_ADD); return(TOKEN_OP_ADD);}
"-"		 {yylval.standard = new Standard(lines, TOKEN_OP_MINUS); return(TOKEN_OP_MINUS);}
"*"		 {yylval.standard = new Standard(lines, TOKEN_OP_MUL); return(TOKEN_OP_MUL);}
"^"		 {yylval.standard = new Standard(lines, TOKEN_OP_POW); return(TOKEN_OP_POW);}
"%"		 {yylval.standard = new Standard(lines, TOKEN_OP_MOD); return(TOKEN_OP_MOD);}
"&"		 {yylval.standard = new Standard(lines, TOKEN_OP_BAND); return(TOKEN_OP_BAND);}
"|"		 {yylval.standard = new Standard(lines, TOKEN_OP_BOR); return(TOKEN_OP_BOR);}
"#"		 {yylval.standard = new Standard(lines, TOKEN_OP_LEN); return(TOKEN_OP_LEN);}
"::"     {yylval.standard = new Standard(lines, TOKEN_SEP_LABEL); return(TOKEN_SEP_LABEL);}
":"		 {yylval.standard = new Standard(lines, TOKEN_SEP_COLON); return(TOKEN_SEP_COLON);}
"//"	 {yylval.standard = new Standard(lines, TOKEN_OP_IDIV); return(TOKEN_OP_IDIV);}
"/"		 {yylval.standard = new Standard(lines, TOKEN_OP_DIV); return(TOKEN_OP_DIV);}
"~="	 {yylval.standard = new Standard(lines, TOKEN_OP_IDIV); return(TOKEN_OP_IDIV);}
"~"		 {yylval.standard = new Standard(lines, TOKEN_OP_WAVE); return(TOKEN_OP_WAVE);}
"=="	 {yylval.standard = new Standard(lines, TOKEN_OP_EQ); return(TOKEN_OP_EQ);}
"="		 {yylval.standard = new Standard(lines, TOKEN_OP_ASSIGN); return(TOKEN_OP_ASSIGN);}
"<<"	 {yylval.standard = new Standard(lines, TOKEN_OP_SHL); return(TOKEN_OP_SHL);}
"<="	 {yylval.standard = new Standard(lines, TOKEN_OP_LE); return(TOKEN_OP_LE);}
"<"		 {yylval.standard = new Standard(lines, TOKEN_OP_LT); return(TOKEN_OP_LT);}
">>"	 {yylval.standard = new Standard(lines, TOKEN_OP_SHR); return(TOKEN_OP_SHR);}
">="	 {yylval.standard = new Standard(lines, TOKEN_OP_GE); return(TOKEN_OP_GE);}
">"		 {yylval.standard = new Standard(lines, TOKEN_OP_GT); return(TOKEN_OP_GT);}
{cv}	 {yylval.standard = new Standard(lines, TOKEN_COMMAVARARG); return(TOKEN_COMMAVARARG);}
"..."	 {yylval.standard = new Standard(lines, TOKEN_VARARG); return(TOKEN_VARARG);}
".."	 {yylval.standard = new Standard(lines, TOKEN_OP_CONCAT); return(TOKEN_OP_CONCAT);}
"."		 {yylval.standard = new Standard(lines, TOKEN_SEP_DOT); return(TOKEN_SEP_DOT);}

{ws}	 	 {/* no action */}
{string} 	 {
				std::string t = std::string(yytext);
				t = t.substr(1, t.size() - 2);

				yylval.standard = new Standard(lines, TOKEN_STRING, t); 
				return(TOKEN_STRING);
			 }
{identifier} {yylval.standard = new Standard(lines, TOKEN_IDENTIFIER, yytext); return(TOKEN_IDENTIFIER);}
{number} 	 {yylval.standard = new Standard(lines, TOKEN_NUMBER, yytext); return(TOKEN_NUMBER);}

%%

/* for lua go compiler
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
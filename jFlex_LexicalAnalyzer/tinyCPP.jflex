// Name: Wayne Wong
// Date: 2/8/2017
// Program: Lexical Analyzer
// (This program is a continuation of the code provided by Dr. Bryant)

import java_cup . runtime . *;
%%

%class tinyCPP_Lexer
%unicode
%line
%column
%cupsym Symbol
%cup
%eofval{
  return symbolFactory . newSymbol ("EOF", Symbol . EOF);
%eofval}

%{
  private SymbolFactory symbolFactory;

  public tinyCPP_Lexer (java . io . InputStream input, SymbolFactory sf) {
    this (input);
    symbolFactory = sf;
  }

  private void echo () { System . out . print (yytext ()); }

  public int position () { return yycolumn; }
%}

Identifier = ([:letter:] | (_ ([:letter:] | [:digit:])))*
Integer    = [:digit:] [:digit:]*
Comment = "//".*

%%
[ \t\n]		{ echo (); }

";"		{ echo (); 
                  return symbolFactory . 
                    newSymbol ("(punctuation, ;)", Symbol . SEMICOLON); }
"."		{ echo (); 
                  return symbolFactory . 
                    newSymbol ("(punctuation, .)", Symbol . PERIOD); }
","		{ echo (); 
                  return symbolFactory . 
                    newSymbol ("(punctuation, ,)", Symbol . COMMA); }
"#"   { echo (); 
                  return symbolFactory . 
                    newSymbol ("(punctuation, #)", Symbol . HASH); }
"{"   { echo (); 
                  return symbolFactory . 
                    newSymbol ("(punctuation, {)", Symbol . LEFTB); }
"}"   { echo (); 
                  return symbolFactory . 
                    newSymbol ("(punctuation, })", Symbol . RIGHTB); }
"["   { echo (); 
                  return symbolFactory . 
                    newSymbol ("(punctuation, [)", Symbol . OPENB); }
"]"   { echo (); 
                  return symbolFactory . 
                    newSymbol ("(punctuation, ])", Symbol . CLOSEB); }
"("   { echo (); 
                  return symbolFactory . 
                    newSymbol ("(punctuation, ()", Symbol . LPAREN); }
")"   { echo (); 
                  return symbolFactory . 
                    newSymbol ("(punctuation, ))", Symbol . RPAREN); }


"<"		{ echo (); 
                  return symbolFactory . 
                    newSymbol ("(operator, <)", Symbol . LT); }
"<<"   { echo (); 
                  return symbolFactory . 
                    newSymbol ("(operator, <<)", Symbol . LL); }
">>"   { echo (); 
                  return symbolFactory . 
                    newSymbol ("(operator, >>)", Symbol . RR); }
"<="		{ echo (); 
                  return symbolFactory . 
                    newSymbol ("(operator, <=)", Symbol . LE); }
">"		{ echo (); 
                  return symbolFactory . 
                    newSymbol ("(operator, >)", Symbol . GT); }
">="		{ echo (); 
                  return symbolFactory . 
                    newSymbol ("(operator, >=)", Symbol . GE); }
"="		{ echo (); 
                  return symbolFactory . 
                    newSymbol ("(operator, =)", Symbol . EQ); }
"=="   { echo (); 
                  return symbolFactory . 
                    newSymbol ("(operator, ==)", Symbol . EQQ); }
"!="		{ echo (); 
                  return symbolFactory . 
                    newSymbol ("(operator, !=)", Symbol . NE); }
"+"		{ echo (); 
                  return symbolFactory . 
                    newSymbol ("(operator, +)", Symbol . PLUS); }
"++"   { echo (); 
                  return symbolFactory . 
                    newSymbol ("(operator, ++)", Symbol . PLUSS); }
"-"		{ echo (); 
                  return symbolFactory . 
                    newSymbol ("(operator, -)", Symbol . MINUS); }
"--"   { echo (); 
                  return symbolFactory . 
                    newSymbol ("(operator, --)", Symbol . MINUSS); }
"*"		{ echo (); 
                  return symbolFactory . 
                    newSymbol ("(operator, *)", Symbol . TIMES); }
"/"		{ echo (); 
                  return symbolFactory . 
                    newSymbol ("(operator, /)", Symbol . SLASH); }
"%"   { echo (); 
                  return symbolFactory . 
                    newSymbol ("(operator, %)", Symbol . MODULO); }
":="		{ echo (); 
                  return symbolFactory . 
                    newSymbol ("(operator, :=)", Symbol . ASSIGN); }
":"    { echo (); 
                  return symbolFactory . 
                    newSymbol ("(operator, :)", Symbol . COLON); }
"&&"    { echo (); 
                  return symbolFactory . 
                    newSymbol ("(operator, &&)", Symbol . AND); }
"||"    { echo (); 
                  return symbolFactory . 
                    newSymbol ("(operator, ||)", Symbol . OR); }


begin		{ echo (); 
                  return symbolFactory . 
                    newSymbol ("(keyword, begin)", Symbol . BEGIN); }
call		{ echo (); 
                  return symbolFactory . 
                    newSymbol ("(keyword, end)", Symbol . CALL); }
const		{ echo (); 
                  return symbolFactory . 
                    newSymbol ("(keyword, const)", Symbol . CONST); }
do		{ echo (); 
                  return symbolFactory . 
                    newSymbol ("(keyword, do)", Symbol . DO); }
end		{ echo (); 
                  return symbolFactory . 
                    newSymbol ("(keyword, end)", Symbol . END); }
if		{ echo (); 
                  return symbolFactory . 
                    newSymbol ("(keyword, if)", Symbol . IF); }
else    { echo (); 
                  return symbolFactory . 
                    newSymbol ("(keyword, else)", Symbol . ELSE); }
odd		{ echo (); 
                  return symbolFactory . 
                    newSymbol ("(keyword, odd)", Symbol . ODD); }
procedure	{ echo (); 
                  return symbolFactory . 
                    newSymbol ("(keyword, procedure)", Symbol . PROC); }
then		{ echo (); 
                  return symbolFactory . 
                    newSymbol ("(keyword, then)", Symbol . THEN); }
var		{ echo (); 
                  return symbolFactory . 
                    newSymbol ("(keyword, var)", Symbol . VAR); }
while		{ echo (); 
                  return symbolFactory . 
                    newSymbol ("(keyword, while)", Symbol . WHILE); }
include   { echo (); 
                  return symbolFactory . 
                    newSymbol ("(keyword, include)", Symbol . INCLUDE); }
iostream   { echo (); 
                  return symbolFactory . 
                    newSymbol ("(keyword, iostream)", Symbol . IOSTREAM); }
using   { echo (); 
                  return symbolFactory . 
                    newSymbol ("(keyword, using)", Symbol . USING); }
namespace   { echo (); 
                  return symbolFactory . 
                    newSymbol ("(keyword, namespace)", Symbol . NAMESPACE); }
std   { echo (); 
                  return symbolFactory . 
                    newSymbol ("(keyword, std)", Symbol . STD); }
int   { echo (); 
                  return symbolFactory . 
                    newSymbol ("(keyword, int)", Symbol . INT); }
main   { echo (); 
                  return symbolFactory . 
                    newSymbol ("(keyword, main)", Symbol . MAIN); }
return   { echo (); 
                  return symbolFactory . 
                    newSymbol ("(keyword, return)", Symbol . RETURN); }  
cout   { echo (); 
                  return symbolFactory . 
                    newSymbol ("(keyword, cout)", Symbol . COUT); }
cin   { echo (); 
                  return symbolFactory . 
                    newSymbol ("(keyword, cin)", Symbol . CIN); }
class   { echo (); 
                  return symbolFactory . 
                    newSymbol ("(keyword, class)", Symbol . CLASS); }
public   { echo (); 
                  return symbolFactory . 
                    newSymbol ("(keyword, public)", Symbol . PUBLIC); }
private   { echo (); 
                  return symbolFactory . 
                    newSymbol ("(keyword, private)", Symbol . PRIVATE); }
NULL   { echo (); 
                  return symbolFactory . 
                    newSymbol ("(keyword, NULL)", Symbol . NIL); }
struct   { echo (); 
                  return symbolFactory . 
                    newSymbol ("(keyword, struct)", Symbol . STRUCT); }


{Comment} { echo (); }

{Integer}	{ echo (); 
                  return symbolFactory . 
                    newSymbol ("(integer, " + yytext () + ")", 
                      Symbol . INTEGER, yytext ()); }
{Identifier}	{ echo (); 
                  return symbolFactory . 
                    newSymbol ("(identifier, " + yytext () + ")", 
                      Symbol . ID, yytext ()); }
.		{ echo (); ErrorMessage . print (yychar, "Illegal character"); }

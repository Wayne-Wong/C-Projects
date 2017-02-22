// Name: Wayne Wong
// Date: 2/8/2017
// Program: Lexical Analyzer
// (This program is a continuation of the code provided by Dr. Bryant)
// Symbol class definition
// Symbol is a class to represent lexical tokens in the PL/0 
// programming language, described in Algorithms + Data
// Structures = Programs by Niklaus Wirth, Prentice-Hall, 1976.

public class Symbol {    // token classes
  public static final int EOF       = -1;
  public static final int BEGIN     =  0;
  public static final int CALL      =  1;
  public static final int CONST     =  2;
  public static final int DO        =  3;
  public static final int END       =  4;
  public static final int IF        =  5;
  public static final int ODD       =  6;
  public static final int PROC      =  7;
  public static final int THEN      =  8;
  public static final int VAR       =  9;
  public static final int WHILE     = 10;
  public static final int ID        = 11;
  public static final int INTEGER   = 12;
  public static final int ASSIGN    = 13;
  public static final int PLUS 	    = '+';
  public static final int MINUS     = '–';
  public static final int TIMES     = '*';
  public static final int SLASH     = '/';
  public static final int EQ        = '=';
  public static final int LT        = '<';
  public static final int GT        = '>';
  public static final int NE        = GT + 1;
  public static final int LE        = NE + 1;
  public static final int GE        = LE + 1;
  public static final int LPAREN    = '(';
  public static final int RPAREN    = ')';
  public static final int COMMA     = ',';
  public static final int PERIOD    = '.';
  public static final int SEMICOLON = ';';
  public static final int HASH      = '#';
  public static final int INCLUDE   = 14;
  public static final int IOSTREAM  = 15;
  public static final int USING     = 16;
  public static final int NAMESPACE = 17;
  public static final int STD       = 18;
  public static final int INT       = 19;
  public static final int MAIN      = 20;
  public static final int COLON     = ':';
  public static final int LEFTB     = '{';
  public static final int RIGHTB    = '}';
  public static final int OPENB     = '[';
  public static final int CLOSEB    = ']';
  public static final int LL        = LT+1;
  public static final int RR        = GT+1;
  public static final int RETURN    = 21;
  public static final int COUT      = 22;
  public static final int CIN       = 23;
  public static final int CLASS     = 24;
  public static final int PUBLIC    = 25;
  public static final int PRIVATE   = 26;
  public static final int AND       = 27;
  public static final int OR        = 28;
  public static final int NIL       = 29;
  public static final int ELSE      = 30;
  public static final int EQQ       = EQ + 1;
  public static final int PLUSS     = 31;
  public static final int MINUSS    = 32;
  public static final int MODULO    = '%';
  public static final int STRUCT    = 33;
}

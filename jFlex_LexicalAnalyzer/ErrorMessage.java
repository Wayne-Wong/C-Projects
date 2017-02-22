// Name: Wayne Wong
// Date: 2/8/2017
// Program: Lexical Analyzer
// (This program is a continuation of the code provided by Dr. Bryant)
// ErrorMessage class
// This class prints error messages.

public class ErrorMessage {

  public static void print (String message) {
    System . out . println ("***** Error: " + message + " *****");
    System . exit (0);
  }

  public static void print (int position, String message) {
    System . out . println ("");
    for (int i = 0; i < position; i++) 
      System . out . print (" ");
    System . out . println ("^");
    print (message);
  }

}

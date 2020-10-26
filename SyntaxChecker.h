#include "GenStack.h"
#include <iostream>
using namespace std;

class SyntaxChecker{
  public:
     //default constructor
    SyntaxChecker();
     //overloaded constructor
    SyntaxChecker(int s);
    //destructor
    ~SyntaxChecker();

    bool delimiters(string file);

    GenStack<char> stack1;

    char parentheses;
    char curly;
    char squareBracket;
};

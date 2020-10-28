#include "SyntaxChecker.h"
#include <iostream>
#include <fstream>

//default constructor
SyntaxChecker::SyntaxChecker(){
  stack1 = GenStack<char>();
  parentheses = '(';
  curly  = '{';
  squareBracket = '[';
}

//overloaded constructor
SyntaxChecker::SyntaxChecker(int s){
  stack1 = GenStack<char>(s);
  parentheses = '(';
  curly  = '{';
  squareBracket = '[';
}

//destructor
SyntaxChecker::~SyntaxChecker(){
  stack1.~GenStack();
}

// checking opening and closing delimiters
bool SyntaxChecker::delimiters(string file){
  int lineCount = 0;
  string line;
  ifstream infile(file);
  while(getline(infile, line)){
       lineCount++;
       //for loop to look at each character in the line
      for(char i : line){
        //checking for open delimiter- adding to the stack
        if((i == '(') || (i == '{') || (i == '[')){
          if(stack1.isFull()){
            stack1.newStack();
          }
          stack1.push(i);
        //closed delimiter- checking for errors
        }
        else if((i == ')') || (i == '}') || (i == ']')){
          //checking if stack is empty
          if(stack1.isEmpty()){
            char expected;
            // checking for extra or missing parentheses
            if(i == ')'){
              expected = parentheses;
            }
            // checking for extra or missing curly brace
            if(i == '}'){
              expected = curly;
            }
            // checking for extra or missing squareBracket
            if(i == ']'){
              expected = squareBracket;
            }
            cout << "Line " << lineCount << ": Expected " << expected << " but it was not found!" << endl;
            cout << " But not found" << endl;
            return false;
          }
          // checking closing parentheses
          else if(i == ')'){
            char current = stack1.pop();
            if(current == squareBracket  || current == curly){
              cout << "Line " << lineCount << " Expected: " << parentheses << " but instead found " << current << endl;
              return false;
            }
          }
          // checking closing curly brace
          else if(i == '}'){
            char current = stack1.pop();
            if(current == squareBracket || current == parentheses){
              cout << "Line " << lineCount << ": Expected " << curly  << " but instead found " << current << endl;
              return false;
            }
          }
          // checking closing squareBracket
          else if(i == ']'){
            char current = stack1.pop();
            if(current == curly || current == parentheses ){
              cout << "Line " << lineCount << ": Expected " << squareBracket << " but instead found " << current << endl;
              return false;
            }
          }
        }
      }
    }
    //checking if stack is not empty once its gone through the file
    if(stack1.isEmpty() == false){
      cout << "The stack isn't empty!!" << endl;
      cout << "Still " << stack1.peek() << " left " << endl;
      return false;
    }
    //checking if stack is empty once its gone through the file
    if(stack1.isEmpty()){
      cout << "File is correct!!!" << endl;
      return true;
    }
  }

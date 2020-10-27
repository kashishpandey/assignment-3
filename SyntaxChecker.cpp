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
  //line count
  int count = 0;
  string line;
  //reading into a file
  ifstream infile(file);
  while(getline(infile, line)){
       count++;
       //for loop to look at each character in the line
      for(char i : line){
        //open delimiter - adding to the stack
        if((i == '(') || (i == '{') || (i == '[')){
          if(stack1.isFull()){
            stack1.newStack();
          }
          stack1.push(i);
        //closed delimiter - checking for errors
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
            cout << "Line " << count << ": Expected " << expected << " but not found" << endl;
            return false;
          }
          // checking closing parentheses
          else if(i == ')'){
            char current = stack1.pop();
            if(current == squareBracket  || current == curly){
              cout << "Line " << count << " Expected: " << parentheses << " but found " << current << endl;
              return false;
            }
          }
          // checking closing curly brace
          else if(i == '}'){
            char current = stack1.pop();
            if(current == squareBracket || current == parentheses){
              cout << "Line " << count << ": Expected " << curly  << " but found " << current << endl;
              return false;
            }
          }
          // checking closing squareBracket
          else if(i == ']'){
            char current = stack1.pop();
            if(current == curly || current == parentheses ){
              cout << "Line " << count << ": Expected " << squareBracket << " but found " << current << endl;
              return false;
            }
          }
        }
      }
    }
    //checking if stack is not empty once its gone through the file 
    if(stack1.isEmpty() == false){
      cout << "Stack is not empty, there's still " << stack1.peek() << " left at the end of the file" << endl;
      return false;
    }
    //checking if stack is empty once its gone through the file
    if(stack1.isEmpty()){
      cout << "File is correct!!!" << endl;
      return true;
    }
  }

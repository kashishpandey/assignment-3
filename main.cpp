#include "SyntaxChecker.h"
#include <iostream>
#include <fstream>
using namespace std;

int main (int argc, char **argv){

  bool loop = true;
  bool output = true;
  // yes or no response from user
  string answer;

  // if user types ./a.out without the file name after
  if(argc == 1){
    cout << "Please enter the file you want checked after ./a.out" << endl;
    return 0;
  }

  string test = argv[1];
  //checking syntax for another file if user wants to pass another file through
  while(loop){
    if(output){
      SyntaxChecker* s = new SyntaxChecker();
      bool count = s->delimiters(test);
      // checking for another file
      if(count){
        cout << "Check another file? : y/n: ";
        cin >> answer;
        // user enters yes
        if(answer == "y"){
          cout << "Please enter the file name: ";
          cin >> test;
          loop = true;
        }
        // user enters no
        if(answer == "n"){
          loop = false;
        }
      }
      else {
        return 0;
      }
    }
  }
}

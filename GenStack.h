#include <iostream>
using namespace std;
template <class T>

class GenStack{
  public:
    //constructor
    GenStack();
    //overloaded constructor
    // ms = maximum size
    GenStack(int ms);
    //destructor
    ~GenStack();

    bool isFull();
    bool isEmpty();

    void newStack();

    T peek();
    T pop();
    void push(T contents);

    int size;
    int top;

    T *myArray;
};

//default constructor
template<class T>
GenStack<T>::GenStack(){
  myArray = new T[128];
  size = 128;
  top = -1;
}

//overloaded constructor
template<class T>
GenStack<T>::GenStack(int ms){
  myArray = new T[ms];
  size = ms;
  top = -1;
}

//destructor
template<class T>
GenStack<T>::~GenStack(){
  delete myArray;
}

//returns if true or false -  checking whether stack is full
template<class T>
bool GenStack<T>::isFull(){
  return(top == size-1);
}

//returns true or false - checking whether stack is empty
template<class T>
bool GenStack<T>::isEmpty(){
  return (top == -1);
}

//double the size of the stack - if the stack is full
template<class T>
void GenStack<T>::newStack(){
  size = size + size;
  T *newStack;
	newStack = new T[size];
	for(int i = 0; i < (size/2); i++){
		newStack[i] = myArray[i];
	}
  myArray = newStack;
}

//returning first element of array
template<class T>
T GenStack<T>::peek(){
  if(isEmpty()){
    cout <<"Stack is empty!!!" << endl;
  }
  else{
    return myArray[top];
  }
}

//popping top of stack
template<class T>
T GenStack<T>::pop(){
  if(isEmpty()){
    cout <<"The stack is empty!!" << endl;
  }
  else{
    return myArray[top--];
  }
}

//pushing to top of the stack
template<class T>
void GenStack<T>::push(T contents){
  if(isFull()){
    cout << "The stack is full!!" << endl;
  }
  else{
    myArray[++top] = contents;
  }
}

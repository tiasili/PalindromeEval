//Tia Silivelio
//stack.cpp
//Purpose: implementation of stack class (stack.h)

#include <iostream>
#include <string>

#include "stack.h"

using namespace std;

Stack::Stack(int size) //constructor
{
  if(size < 3)
    size = 50;
  max = size;
  stackList = new char[max];
  top = 0;
}

Stack::~Stack() //destructor
{
  delete [] stackList;
}

Stack::Stack(const Stack& s) //copy constructor
{
  max = s.max;
  stackList = new char[max];
  top = s.top;
  
  for(int i = 0; i < max; i++)
    stackList[i] = s.stackList[i];
}

Stack& Stack::operator=(const Stack& rhs) //overloaded assignment operator
{
  if(this != &rhs){
    delete [] stackList;
    max = rhs.max;
    stackList = new char[max];
    top = rhs.top;
    for(int i = 0; i < max; i++)
      stackList[i] = rhs.stackList[i];
  }
  return* this;
}

void Stack::push(char d)
{
  if(isFull())
    resize();
  
  stackList[top] = d;
  top++;
}

char Stack::pop()
{
  if(isEmpty())
    throw EmptyStack();
  else
    top--;

  return stackList[top];
}

bool Stack::isEmpty() const
{
  return top == 0;
}

bool Stack::isFull() const
{
  return top == max - 1;
}

void Stack::resize()
{
  char* resize;
  resize = new char[max*2];
  
  for(int i = 0; i < max; i++)
    resize[i] = stackList[i];
  
  delete [] stackList;
  stackList = resize;

  max = max * 2;
}


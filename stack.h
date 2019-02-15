//Tia Silivelio
//stack.h

#ifndef STACK_H
#define STACK_H

using namespace std;

class Stack
{
 public:
  Stack(int s = 100);
  ~Stack();
  Stack(const Stack& s);
  Stack& operator=(const Stack& rhs);
  void push(int d);
  int pop();
  bool isEmpty() const;
  //determines if stack is empty, returns 0 if true
  bool isFull() const;
  //determines if stack is full
  //calls resize function if capacity is exceeded
 private:
  int* stackList; //array that holds integers of stack
  int size;
  int top; //integer at top of stack (LIFO)
  void resize();
};

#endif

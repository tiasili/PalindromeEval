//Tia Silivelio
//LLQ.h
//Purpose: The LLQ class declares functions for the main function (P2.cpp) to use. It
//also declares variables to be used for the functions in the LLQ implementation.

#ifndef LLQ_H
#define LLQ_H
#include <iostream>

using namespace std;

class LLQ
{
 public:
  LLQ();
  ~LLQ();
  void enQueue(int d);
  int deQueue();
  //pre-condition: in order to dequeue integers, queue cannot be empty
  bool isEmpty() const;
  void clear(); //resets values in queue
  int getSize(); //gets size of linked list
  void flush(); //removes negative integers from queue
 private:
  LLQ(const LLQ& q); //function is suppressed in private
  void operator=(const LLQ& q);

  struct qNode //node used to traverse through linked list
  {
    int data;
    qNode* next;
  };

  qNode* head; 
  qNode* tail;
};

#endif

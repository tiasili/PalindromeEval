//Tia Silivelio
//Queue.h
//Purpose: The Queue class declares functions for the main function (main.cpp) to use. It
//also declares variables to be used for the functions in the Queue implementation.

#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>

using namespace std;

class Queue
{
 public:
  Queue();
  ~Queue();
  void enQueue(int d);
  int deQueue();
  //pre-condition: in order to dequeue integers, queue cannot be empty
  bool isEmpty() const;
  void clear(); //resets values in queue
  int getSize(); //gets size of linked list
 private:
  Queue(const Queue& q); //function is suppressed in private
  void operator=(const Queue& q);

  struct qNode //node used to traverse through linked list
  {
    int data;
    qNode* next;
  };

  qNode* head; 
  qNode* tail;
};

#endif

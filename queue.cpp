//Tia Silivelio
//queue.cpp
//Purpose: implementation of queue class (queue.h)

#include <iostream>
#include "queue.h"

using namespace std;

Queue::Queue() //constructor
{
  front = nullptr;
  tail = nullptr;
}

Queue::~Queue() //destructor
{
  qNode* delPtr;

  while (front != nullptr){ //while (front != tail)
    delPtr = front;
    front = front->next;
    delete delPtr;
  }
}

Queue::Queue(const Queue& q) //copy constructor
{
/*
  front = nullptr;
  tail = nullptr;

  qNode* temp; 
  temp = q.front;
*/
    
    front = q.front;
    tail = q.front;
    
    while(front != nullptr){
        enqueue(front->data);
        tail = front;
        front = front->next;
    }
}

Queue& Queue::operator=(const Queue& rhs) //overloaded assignment operator
{
  qNode* delPtr;
  qNode* ptr; //walks through the list

  if(this != &rhs){ //copy constructor
    while(front != nullptr){
      delPtr = front;
      front = front->next;
      delete delPtr;
    }
    if(rhs.front == nullptr){
      front = nullptr;
      tail = nullptr;
    }else{ //needed to copy list in rhs
      ptr = rhs.front;
      front = new qNode;
      front->data = ptr->data;
      tail = front;
      ptr = ptr->next;
      while(ptr != nullptr){
        tail->next = new qNode;
        tail = tail->next;
        tail->data = ptr->data;
        ptr = ptr->next;
      }
      tail->next = nullptr;
    }
  }
  
  return* this;
}

void Queue::enqueue(char d)
{
  qNode *temp = nullptr;

  temp = new qNode;
  temp->data = d;
  temp->next = nullptr;

  if(isEmpty())
    front = temp;
  else
    tail->next = temp;

  tail = temp;
}

char Queue::dequeue()
{
  qNode* delPtr = nullptr;
  char d;
  
  if(isEmpty()){
    throw EmptyQueue();
  }else{
    delPtr = front;
    d = front->data;
    front = front->next;
    delete delPtr;
    
    if(front == nullptr)
      tail = nullptr;
    
    return d;
  }
}

bool Queue::isEmpty() const
{
  return front == nullptr;
}


#ifndef _MYQUEUE_H_
#define _MYQUEUE_H_

using namespace std;

class MyQueue {
public:
   MyQueue(int size);
   ~MyQueue();
   void EnQueue(double elem);
   double DeQueue();
   int CurrentSize();
   bool IsEmpty() const;
   bool IsFull() const;

private:
   double *elements; /* To declare a dynamic array of double elements for a queue (using C++ keyword new) */
   int front, rear;  /* Indexes of the front and rear elements of the queue */
   int array_length;  /* Max number of the elements that could be in the queue */
};

MyQueue::MyQueue(int size) {
   // TODO
}


MyQueue::~MyQueue() {
   // TODO
}

void MyQueue::EnQueue(double elem) {
   // TODO
}

double MyQueue::DeQueue() {
   // TODO
}

int MyQueue::CurrentSize() {
   // TODO
}

bool MyQueue::IsEmpty() const {
   // TODO
}

bool MyQueue::IsFull() const {
   // TODO
}

#endif
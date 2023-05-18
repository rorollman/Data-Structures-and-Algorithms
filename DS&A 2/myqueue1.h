
#ifndef _MYQUEUE1_H_
#define _MYQUEUE1_H_
#include <iostream>
#include <stdlib.h>

using namespace std;

class MyQueue {
private:
   int *queueArray; /* To declare a dynamically allocated array of integer elements for a queue (using C++ keyword new) */
   int rear, front;  /* The front and rear indexes of the queue */
   int queueSize; /* The length of an array that implements a queue */
   int numItems;      /* The counter variable to keep track of the elements in the queue */

public:
   MyQueue(int size);
   ~MyQueue();
   void EnQueue(int elem);
   int DeQueue();
   bool IsEmpty() const;
   bool IsFull() const;
};

MyQueue::MyQueue(int size) {
    queueArray = new  int[size];
    queueSize = size;
    front = -1;
    rear  = -1;
    numItems = 0;
}

MyQueue::~MyQueue() {
    delete [] queueArray;
}

void MyQueue::EnQueue(int elem) {
    if (IsFull()) {
        cout  << "The queue is full.\n";
    }
    else {
    //calc new rear pos
        rear = (rear+1)%queueSize;
        //insert new item
        queueArray[rear] = elem;
        //update item count
        numItems++;
    }
}

int MyQueue::DeQueue() {
    int elem;
    if (IsEmpty()) {
        cout << "The queue is empty.\n";
    }
    else {
    //move front
        front = (front+1)%queueSize;
        //get front item
        elem = queueArray[front];
        //update item count
        numItems--;
    }
    return elem;
}

bool MyQueue::IsEmpty() const {
    bool status;

    if (numItems) {
        status = false;
    }
    else {
    status = true;
    }
    return status;
}

bool MyQueue::IsFull() const {
    bool status;

    if (numItems < queueSize) {
        status = false;
    }
    else {
    status = true;
    }
    return status;
}

#endif



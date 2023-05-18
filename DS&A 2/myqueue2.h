#ifndef _MYQUEUE2_H_
#define _MYQUEUE2_H_
#include <stdlib.h>

using namespace std;

class MyQueue {
public:
   MyQueue(int size);
   ~MyQueue();
   void EnQueue(int elem);
   int DeQueue();
   int CurrentSize();
   bool IsEmpty();
   bool IsFull();

private:
   int *queueArray; /* To declare a dynamically allocated array of integer elements for a queue (using C++ keyword new) */
   int front, rear;  /* The front and rear indexes of the queue */
   int queueSize; /* The length of an array that implements a queue */
                     /* Keep in mind that the queue will only hold up to (array_length - 1) elements */
                     /* In other words, array_length should be the maximum capacity of the queue plus one */
};

MyQueue::MyQueue(int size) {
    queueArray = new int[size];
    queueSize = size;
    front = -1;
    rear = -1;
}

MyQueue::~MyQueue() {
    delete [] queueArray;
}

void MyQueue::EnQueue(int elem) {
    if (IsFull()){
        cout << "Nothing can be enqueued since the queue is full!\n";
    }
    else if (front == -1) {
        front = 0;
        rear = 0;
        queueArray[rear] = elem;
    }
    else {
    rear = (rear+1)%queueSize;
        queueArray[rear] = elem;
    }
}

int MyQueue::DeQueue() {
    int data;

    if (IsEmpty()) {
        exit(0);
    }
    else {
    data = queueArray[front];
        if (front == rear) {
            front = -1;
            rear  =  -1;
        } else {
            front = (front+1)%queueSize;
        }
    }
    return data;
}

int MyQueue::CurrentSize() {
    int size;
    size = abs(abs(queueSize-front)-abs(queueSize-rear));
    return size;
}

bool MyQueue::IsEmpty() {
    bool status;
    if (front == -1) {
        status = true;;
    }
    else {
    status = false;
    }
    return status;
}

bool MyQueue::IsFull() {
    bool status;
    if ((front == 0 && rear == queueSize-1) || (rear == (front-1)%(queueSize-1))) {
        status = true;
    }
    else {
    status = false;
    }
    return status;
}

#endif

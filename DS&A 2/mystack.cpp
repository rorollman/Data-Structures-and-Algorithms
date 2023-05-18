#include <iostream>
#include "mystack.h"
#include <stdlib.h>

using namespace std;

/* Constructor
 * Usage: MyStack(val);*/

MyStack::MyStack(int size) {
    stackArray = new int[size];
    max_size = size;
    top = -1;
}


/* Destructor */

MyStack::~MyStack() {
    delete [] stackArray;
}

/* Functions: Push, Pop
 * Usage: st.Push(val); val = st.Pop();*/

void MyStack::Push(int elem) {
    if (IsFull()) {
        cout << "The stack is full.\n";    //error message
    }
    else {
        top++;
        stackArray[top] = elem;
    }
}

int MyStack::Pop() {
    char elem1=0;
    if (IsEmpty()) {
        cout << "The stack is empty.\n"; //error message
        exit(0);
    }
    else{
        elem1 = stackArray[top];
        top--;
    }
    return elem1;
}

/*
 * Functions: IsEmpty, IsFull
 * Usage: if (!IsEmpty()) ...
 * -----------------------------------
 * Return true if the stack is empty (IsEmpty) or full (IsFull).
 */

bool MyStack::IsEmpty() const {
    bool status;
    
    if (top == -1) {
        status = true;
    }
    else {
        status = false;
    }
    return status;
}

bool MyStack::IsFull() const {
    bool status;
    
    if (top == max_size - 1) {
        status = true;
    }
    else {
        status = false;
    }
    return status;
}


#include <iostream>
#include "mystack.h"
#include <stdlib.h>

using namespace std;

/*
 * Constructor
 * Usage: MyStack(val);
 * -------------------------
 * A new stack is created and initialized. The initialized stack is made empty.
 * The parameter 'size' is used to determine the maximum number of integer 
 * elements that can be held in the stack.
 */

MyStack::MyStack(int size) {
    stackArray = new int[size];
    max_size = size;
    top = -1;
}


/* Destructor
 * -----------------------
 * Release the memory allocated for the stack.
 */

MyStack::~MyStack() {
    delete [] stackArray;
}

/*
 * Functions: Push, Pop
 * Usage: st.Push(val); val = st.Pop();
 * --------------------------------------------
 * These are the fundamental stack operations that add an element to
 * the top of the stack and remove an element from the top of the stack.
 * A call to pop from an empty stack or to push on a full stack is an error.
 * Make use of IsEmpty()/IsFull() (see below) to avoid the error.
 */

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


#include <iostream>
#include <stdlib.h>
#include "mystack.h"

using namespace std;

void PostfixTest();

int main()
{
   cout << "Testing the basic functions of your stack..." << endl;
   cout << "Please enter the max size of your stack: ";
   int test_size;
   int  catchVar;
   cin >> test_size;

   MyStack test_stack(test_size);

   while(1) {
      cout << "Please enter 'p' for push, 'o' for pop, 'e' for exit: ";
      char user_choice;
      cin >> user_choice;
      
      if(user_choice == 'e')
         break;

      switch (user_choice) {
         case 'p':			
            if(!test_stack.IsFull()) {
               cout << "Please enter an integer value you would like to push: ";
               int val;
               cin >> val;
               test_stack.Push(val);
            }
            else
               cout << "Nothing can be pushed in since the stack is full!" << endl;
            break;
         case 'o':
            if(!test_stack.IsEmpty()) {
                catchVar = test_stack.Pop();
                cout << catchVar << " has been popped out" << endl;
                break;
              }
            else {
               cout << "Nothing has been popped out since the stack is empty!" << endl;
            break;
            }
            default:
              cout << "Invalid user-input character. Please try again." << endl;
              break;
      }
   }

   cout << "Now, start to use a stack to evaluate postfix expressions..." << endl;
   PostfixTest();
	
   return 0;
}

void PostfixTest() {
    MyStack operand_stack(100);
    int op1=0,op2=0, counter=0, operators=0;
    cout << "Please enter the operands (integers 1~9) and operators (+, -, *, /) one by one..." << endl;
    cout << "and enter '=' to indicate the end of the expression and to output the result." << endl;
    
    while(1) {
        char input_holder;
        cin >> input_holder;
        if (counter==0 || counter==1) {
            if (input_holder == '=') {
                cout << "The entered postfix expression was not a legal one.\n";
                exit(0);
            }
            else if (input_holder == '+') {
                cout << "The entered postfix expression was not a legal one.\n";
                exit(0);
            }
            else if (input_holder == '-') {
                cout << "The entered postfix expression was not a legal one.\n";
                exit(0);
            }
            else if (input_holder == '*') {
                cout << "The entered postfix expression was not a legal one.\n";
                exit(0);
            }
            else if (input_holder == '/') {
                cout << "The entered postfix expression was not a legal one.\n";
                exit(0);
            }
        }
        if (input_holder == '=') {
            break;
        }
        if (input_holder == '+') {
            op1 = operand_stack.Pop();
            op2 = operand_stack.Pop();
            operand_stack.Push(op2+op1);
            operators++;
        }
        else if (input_holder == '-') {
            op1 = operand_stack.Pop();
            op2 = operand_stack.Pop();
            operand_stack.Push(op2-op1);
            operators++;
        }
        else if (input_holder == '*') {
            op1 = operand_stack.Pop();
            op2 = operand_stack.Pop();
            operand_stack.Push(op2*op1);
            operators++;
        }
        else if (input_holder == '/') { //can't divide by 0
            op1 = operand_stack.Pop();
            op2 = operand_stack.Pop();
            if (op2 == 0) {
                cout << "Cannot divide by zero, exiting program . . .\n";
                exit(0);
            }
            operand_stack.Push(op2/op1);
            operators++;
        }
        else {
            int x = input_holder - '0';
            operand_stack.Push(x);
            counter++;
        }
    }
    if (counter-1 != operators) {
        cout << "The entered postfix expression was not a legal one.\n";
        exit(0);
    }
    cout << "The entered postfix expression results in ";
    cout << operand_stack.Pop() << endl;
}


#include <iostream>
#include <stdlib.h>
#include "myqueue1.h"
// Make sure to include the correct header file, so that you can test out your implementation
// For example: #include "myqueue1.h" (for the first method that uses a counter variable)
//              #include "myqueue2.h" (for the second method based only on the front and rear indexes)

using namespace std;

int main() {
   cout << "Testing the basic functions of your queue..." << endl;
   cout << "Please enter the max size/capacity of your queue: ";
   int capacity;
   cin >> capacity;

   MyQueue test_queue(capacity);

   while(1) {
      cout << "Please enter 'e' for enqueue, 'd' for dequeue, and 's' for stop: ";
      char user_choice;
      cin >> user_choice;

      if(user_choice == 's')
         break;

      switch(user_choice) {
         case 'e':
            if(!test_queue.IsFull()) {
               cout << "Please enter an integer-type value you want to enqueue: ";
                  int val;
                  cin >> val;
                  test_queue.EnQueue(val);
        }
            else
               cout << "Nothing can be enqueued since the queue is full!" << endl;
            break;
         case 'd':
            if(!test_queue.IsEmpty())
               cout << test_queue.DeQueue() << " has been popped out." << endl;
            else
               cout << "Nothing has been popped out since the queue is empty!" << endl;
            break;
         default:
            cout << "Invalid user-input character. Please try again." << endl;
      }
   }

   return 0;
}

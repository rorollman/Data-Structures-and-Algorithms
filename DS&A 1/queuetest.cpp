#include <iostream>
#include "myqueue.h"

using namespace std;

int main() {
   cout << "Testing the basic functions of your queue..." << endl;
   cout << "Please enter the max size of your queue: ";
   int test_size;
   cin >> test_size;

   MyQueue test_queue(test_size);

   while(1) {
      cout << "Please enter 'e' for enqueue, 'd' for dequeue, and 's' for stop: ";
      char user_choice;
      cin >> user_choice;

      if(user_choice == 's')
         break;

      switch(user_choice) {
         case 'e':
            if(!test_queue.IsFull()) {
               cout << "Please enter a double-type value you want to enqueue: ";
                  double val;
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

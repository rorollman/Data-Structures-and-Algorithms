#include <iostream>
#include "myqueue2.h"
// Include one of your queue header files to use its corresponding queue implementation

using namespace std;

int CountStudent(int tshirt_stack[], int stack_size, int student_queue[], int queue_size) {
    int catchStudent;
    //counters for how many types of shirts are preferred
    int ones=0;
    int zeros=0;

    //creating queue of students
    MyQueue students(queue_size);

    //finding the number of each preferred shirt
    for (int i=0; i<queue_size; i++) {
        if (student_queue[i] == 1) {
            ones++;
        }
    if (student_queue[i] == 0) {
            zeros++;
        }
    students.EnQueue(student_queue[i]);
    }

    //counter for traversing stack of shirts
    int i=0;

    //while the queue is not empty, do this stuff
    while (!students.IsEmpty()) {
        //take first student from queue
        catchStudent = students.DeQueue();
        //and compare to top shirt in stack
        if (tshirt_stack[i]==catchStudent) {
            //if they match, update student preference counter and update index
            if (tshirt_stack[i]==0) {
                zeros--;
                i++;
            }
            else if (tshirt_stack[i]==1){
                ones--;
                i++;
            }
        }
        else if (tshirt_stack[i]!=catchStudent) {
            //no more students who prefer 0 are in queue
            if (tshirt_stack[i]==0 && zeros==0) {
                break;
            }
            //no more students who prefer 1 are in queue
            if (tshirt_stack[i]==1 && ones==0) {
                break;
            }
            //if there are still students in queue who prefer,
            //push the current student to the end of line
            else {
                students.EnQueue(catchStudent);
            }
    }
    }
    //returning the count of students that would be left over in queue
    return ones+zeros;
}

void Testing(int tshirts[], int tshirt_size, int students[], int student_size) {
   cout << "Testing the CountStudent function..." << endl; 
   cout << "Student Queue: "; 
   for (int i = 0; i < student_size; i++){
     cout << students[i] << " "; 
   }
   cout << endl; 
   cout << "T-shirt Stack: "; 
   for (int i = 0; i < tshirt_size; i++){
     cout << tshirts[i] << " "; 
   }
   cout << endl; 
   cout << "Number of students who are unable to have the t-shirts is: " << CountStudent(tshirts, tshirt_size, students, student_size) << endl; 
}

int main() {
   
   /* Test Case 1 */
   const int t1_student_size = 4;
   int t1_students[t1_student_size] = {1,1,0,0};
   const int t1_tshirt_size = 4;
   int t1_tshirts[t1_tshirt_size] = {0,1,0,1};
   Testing(t1_tshirts, t1_tshirt_size, t1_students, t1_student_size);

   /* Test Case 2 */
   const int t2_student_size = 6;
   int t2_students[t2_student_size] = {1,1,1,0,0,1};
   const int t2_tshirt_size = 6;
   int t2_tshirts[t2_tshirt_size] = {1,0,0,0,1,1};
   Testing(t2_tshirts, t2_tshirt_size, t2_students, t2_student_size);

   /* Test Case 3 */
   const int t3_student_size = 7;
   int t3_students[t3_student_size] = {1,1,0,0,1,1,0};
   const int t3_tshirt_size = 7;
   int t3_tshirts[t3_tshirt_size] = {0,1,0,1,0,0,0};
   Testing(t3_tshirts, t3_tshirt_size, t3_students, t3_student_size);
      
   return 0;
}

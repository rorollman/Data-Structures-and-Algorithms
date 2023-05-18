// pointers to structures
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

struct student {
  string name;
  double gpa;
};

void input(student *sptr);

int main ()
{
  string name;

  student s1;
    student *sptr;
    sptr = &s1;
    input (&s1);
    
  cout << "\nYou have entered:\n";
    cout << s1.name;
  cout << " (" << s1.gpa << ")\n";

  return 0;
}
void input(student *sptr) {
    cout << "Enter title: ";
    cin >> sptr->name;
    cout << "Enter year: ";
    cin >> sptr->gpa;
}

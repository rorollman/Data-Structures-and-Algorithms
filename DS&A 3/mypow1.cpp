#include <iostream>

using namespace std;

double Pow(double x, int n) {
    if (n==0) {
        return 1;
    }
    return x*Pow(x, n-1);
}

int main()
{
   cout << "To calculate x^n..." << endl;
    
   double x;
   int n;
   cout << "Please enter x: ";
   cin >> x;
   cout << "Please enter n: ";
   cin >> n;
   
   if(x == 0) {
      if (n > 0) {
         cout << 0 << endl;
      } else {
         cout << "x^n is not defined." <<endl;
      }
   } else {
      cout << Pow(x,n) << endl;
   }

   return 0;
}


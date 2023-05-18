#include <iostream>

using namespace std;

bool CheckPowerOfTwo(int n) {
    if (n==1) {
        return true;
    }
    else if (n%2 != 0 || n==0) {
        return false;
    }
    return CheckPowerOfTwo(n/2);
}

int main() {

   int val;
   cout << "Enter an integer (0,1,...): ";
   cin >> val;
 
   if (CheckPowerOfTwo(val)) {
      cout << "Power of two: true\n";
   } else {
      cout << "Power of two: false\n";
   }
   
   return 0;
}

#include <iostream>

using namespace std;

// This function exchanges the values of var1 and var2.
void Swap(int& var1, int& var2)
{
    int temp;
    temp = var1;
    var1 = var2;
    var2 = temp;
}

// This function performs the 'percolate down' operation from node arr[index].
void PercolateDown(int arr[], int index, int size)
{
    int smallest = index;
    int left = 2*index+1;
    int right = 2*index+2;
    
    if (left<size && arr[left]<arr[smallest]) {
        smallest = left;
    }
    if (right<size && arr[right]<arr[smallest]) {
        smallest = right;
    }
    if (smallest != index) {
        Swap(arr[index], arr[smallest]);
        PercolateDown(arr, smallest, size);
    }
}

// This function swaps the minimum-value element with the last element
// in arr[first..last] and leaves (does not delete) the minimum-value element.
// After DeleteMin, the heap shrinks by 1.
void DeleteMin(int arr[], int& last)
{
    int lastelem = arr[last-1];
    arr[0] = lastelem;
    last = last-1;
    PercolateDown(arr, 0, last);
}

// This functions coverts the array arr[] to a heap, i.e., it has the *head-order*
// property while it is interpreted as a complete binary tree.
void BuildHeap(int arr[], int size)
{
    for (int i = (size/2)-1; i >= 0; i--) {
        PercolateDown(arr, size, i);
    }
}

// This is the 'heapsort' function that sorts the array arr[] in *descending* order.
// You may want to use the BuildHeap and DeleteMin functions in this function.
void Heapsort(int arr[], int size)
{
    BuildHeap(arr, size);
    for (int i = size-1; i>=0; i--) {
        Swap(arr[0], arr[i]);
        PercolateDown(arr, i, size);
    }
}

int main()
{
   cout << "Please enter the length (number of elements) of the input array: ";
   int size;
   cin >> size;

   if(size <= 0) {
      cout << "Illegal input array length!" << endl;
      return 0;
   }

   int* arr = new int[size+1];

   cout << "Please enter each element in the array" << endl;
   cout << "(each element must be an integer within the range of int type)." << endl;
   for(int i = 1; i <= size; i++) {
      cout << "arr[" << i << "] = ";
      cin >> arr[i];
   }

   cout << "The input array arr[] is: ";
   for(int i = 1; i < size; i++)
      cout << arr[i] << ",";
   cout << arr[size] << endl;

   Heapsort(arr,size);

   cout << "After heapsort, the sorted array arr[] is: ";
   for(int i = 1; i < size; i++)
      cout << arr[i] << ",";
   cout << arr[size] << endl;

   delete [] arr;

   return 0;
}

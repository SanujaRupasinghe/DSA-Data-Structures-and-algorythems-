#include <iostream>
using namespace std;
  
// function to heapify the tree
// in here arr is the array, n is the size of the array and root is the root
void heapify(int arr[], int n, int root)
{
   // find largest among root, left child and right child
   int largest = root;
   int left = 2*root + 1;
   int right = 2*root + 2;
  
   if (left < n && arr[left] > arr[largest])
   largest = left;
  
   if (right < n && arr[right] > arr[largest])
   largest = right;
  
   // swap and continue heapifying if root is not largest
   if (largest != root)
   {
   swap(arr[root], arr[largest]);
   heapify(arr, n, largest);
   }
  
   
}
  

void heapSort(int arr[], int n)
{
   // build heap
   for (int i = n / 2 - 1; i >= 0; i--)
   heapify(arr, n, i);
  
   // extract an element from heap one by one
   for (int i=n-1; i>0; i--)
   {
   // move current root to end
   swap(arr[0], arr[i]);
  
   // call max heapify on the reduced heap
   heapify(arr, i, 0);
   }
}

  
/* print contents of array */
void displayArray(int arr[], int n)
{
   for (int i=0; i<n; ++i)
   cout << arr[i] << " ";
   cout << "\n";
}
  

// main program
int main()
{
   int heap_arr[] = {4,17,3,12,9,6};
   int n = sizeof(heap_arr)/sizeof(heap_arr[0]);
   cout<<"Input array"<<endl;
   displayArray(heap_arr,n);
  
   heapSort(heap_arr, n);
  
   cout << "Sorted array"<<endl;
   displayArray(heap_arr, n);
}
#include <iostream>
using namespace std;

void reverseArray(int arr[], int A){
    // initialize values of start and end of the array
    int start = 0;
    int end = A - 1;

    while (start < end) { 
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        // this code moves towerds the center of the array
        start++;
        end--;
    }  
}

void printArr(int arr[], int N){
    for (int i = 0; i < N; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    int vals[8] = {1,2,3,4,5,6,7,8};
    int N = 8;

    printArr(vals, N);
    reverseArray(vals, N);
    printArr(vals, N);
}

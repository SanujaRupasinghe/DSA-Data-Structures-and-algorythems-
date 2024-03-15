#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    // Initialize a vector to save the heap
    // Number of Quaries
    vector<int> heap;
    int iterations;      
    cin >> iterations;

    while (iterations--) {
        int operation;
        cin >> operation;

        // if opreation is 1 then insert the value to the heap
        if (operation == 1) {
            
            int x;
            cin >> x;
            heap.push_back(x);
            //Re-heapify the vector
            push_heap(heap.begin(), heap.end(), greater<int>());
  
        } 
        // if opreation is 2 then delete the value from the heap
        else if (operation == 2) {
            
            int x;
            cin >> x;
            auto it = find(heap.begin(), heap.end(), x);
            if (it != heap.end()) {
                *it = heap.back();
                heap.pop_back();
                // Convert the vector into a max-heap
                make_heap(heap.begin(), heap.end(), greater<int>());
            }
            
        } 
        // if operation is 3 then print the minimum value of the heap
        else if (operation == 3) {
  
            cout << heap.front() << endl;
            
        }
    }

return 0;
}
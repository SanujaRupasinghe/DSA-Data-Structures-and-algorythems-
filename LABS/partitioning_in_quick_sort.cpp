#include <iostream>
#include <vector>

using namespace std;

void partitioning(vector<int>& arr, int pivot){
    vector<int> left;
    vector<int> right;
    vector<int> equal;

    for(int i = 0; i < arr.size(); i++){
        if(arr[i] < pivot){
            left.push_back(arr[i]);
        }
        else if(arr[i] > pivot){
            right.push_back(arr[i]);
        }
        else{
            equal.push_back(arr[i]);
        }
    }

    // Combine vectors into one
    arr.clear();
    arr.insert(arr.end(), left.begin(), left.end());
    arr.insert(arr.end(), equal.begin(), equal.end());
    arr.insert(arr.end(), right.begin(), right.end());
}

int main(){
    vector<int> arr = {4, 5, 3, 7, 2};
    int pivot = arr[0];
    partitioning(arr, pivot);
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
}

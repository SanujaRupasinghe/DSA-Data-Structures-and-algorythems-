#include <iostream>
#include <vector>
using namespace std;

int calSum(vector<vector<int>> arr, int i, int j){
    //for given i and j find the sum of the hourglass
    int sum = arr[i][j] + arr[i-1][j] + arr[i-1][j-1] + arr[i-1][j+1] + arr[i+1][j] + arr[i+1][j-1] + arr[i+1][j+1];
    return sum;
}


int findMax(vector<vector<int>> arr) {
    int j, i;
    int maxVal = 0;
    for (i = 1; i<= (int) arr.size() - 2; i++){
        for (j = 1; j<= (int) arr.size() - 2; j++){
            int sumVal = calSum(arr, i, j);
            if (sumVal > maxVal){
                maxVal = sumVal;
            }
        }
    }
    return maxVal;
}

int main(){

    vector<vector<int>> A{
        {0, 1, 0, 1, 0, 1},
        {1, 0, 1, 0, 1, 0},
        {0, 1, 0, 1, 0, 1},
        {1, 0, 1, 0, 1, 0},
        {0, 1, 0, 1, 0, 1},
        {1, 0, 1, 0, 1, 1}
    };

    int maximum = findMax(A);
    cout << maximum;

}
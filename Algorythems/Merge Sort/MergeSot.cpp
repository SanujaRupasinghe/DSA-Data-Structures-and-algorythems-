#include<iostream>
#include<vector>
//merge sort

merge(int arr[], int l,  int m, int r){
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)  // populate the left array
    {
        L[i] = arr[l+i];
    }
    for (int i = 0; i < n2; i++)  // populate the right array
    {
        R[i] = arr[m+1+i];
    }

    int i = 0, j = 0, k = l;     // merge the two arrays
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])   // if the left array is less than the right array
        {
            arr[k] = L[i];      
            i++;
        }else{
            arr[k] = R[j];  // if the right array is less than the left array
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
    
}

// merge sort
void mergeSort(int arr[], int l, int r){
    if (l < r)
    {
        int m = (l+r)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
    
}

int main(){
    int myArr[5];
    for (int i = 0; i < 5; i++)
    {
        std::cin>>myArr[i];
    }

    //before sorting
    std::cout<<"Before sorting"<<std::endl;
    for (int i = 0; i < 5; i++)
    {
        std::cout<<myArr[i]<<" ";
    }
    std::cout<<std::endl;

    //here merge sort
    mergeSort(myArr, 0, 4);

    //after sorting
    std::cout<<"After sorting"<<std::endl;
    for (int i = 0; i < 5; i++)
    {
        std::cout<<myArr[i]<<" ";
    }
    return 0;
}
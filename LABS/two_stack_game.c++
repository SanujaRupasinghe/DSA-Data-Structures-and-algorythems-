int twoStacks(int maxSum, vector<int> a, vector<int> b) {
    int sum = 0;
    int count = 0;
    int i = 0;
    int j = 0;

    //this part of the code is to check the sum of the elements in the first array
    while (i < a.size() && sum + a[i] <= maxSum) {
        sum += a[i];
        i++;
    }
    count = i;

    //this part of the code is to check the sum of the elements in the second array
    while (j < b.size()) {
        sum += b[j];
        j++;

        //this part of the code is to check if the sum is greater than the maxSum
        while (sum > maxSum && i > 0) {
            i--;
            sum -= a[i];
        }
        //this part of the code is to check if the sum is less than the maxSum
        if (sum <= maxSum && i + j > count) {
            count = i + j;
        }
    }
    return count;
}
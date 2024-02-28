/*
 * Complete the 'powerSum' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER X
 *  2. INTEGER N
 */


// Function to find the number of ways to express a given number X
// as the sum of distinct powers of integers, each raised to the power of N.
int powerSum(int X, int N, int num = 1) {
    // Base case: If X is zero, we have found a valid combination,
    // so we increment the count and return 1.
    if (X == 0) {
        return 1; // Return 1 to indicate a valid combination is found.
    }
    
    // Base case: If X becomes negative or the current number raised to power N
    // exceeds X, no valid combination is possible, so we return 0.
    if (X < 0 || pow(num, N) > X) {
        return 0; // Return 0 to indicate no valid combination is found.
    }
    
    // Recursive case: We have two possibilities:
    // 1. Include the current number and recursively check for the remaining sum.
    // 2. Exclude the current number and move on to the next one.
    return powerSum(X - pow(num, N), N, num + 1) + powerSum(X, N, num + 1);
}


int main(){
    int X, N;
    std::cin>>X>>N;
    std::cout<<powerSum(X, N);
    return 0;
}
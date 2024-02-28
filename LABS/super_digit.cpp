#include<iostream>
#include<vector>
/*
 * Complete the 'superDigit' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING n
 *  2. INTEGER k
 */
//this code  use recursion to solve the problem

int superDigit(string n, int k){
    long sum = 0 ;  //initialize the digit sum to 0

    string n_;   // initialize the string to store the concatenated string
    for (int i = 0; i < k; i++) {
        n_.append(n);  //concatinate the string k times
    }
    
    long size = n_.length() ;
    for (long i = 0; i < size; i++) {
        int char_num = n_[i] - '0' ;    //Convert each character into integers and add them.
        sum += char_num ;     // add the digits
    }

    if (sum < 10) { //Base case: where only one digit is present.
        return sum;
    }
    else { //Recursive case: 2nd parameter is 1 beacuase we don't need to concatenate it after the 1st time.
        return superDigit(to_string(sum), 1);
    }

}

int main(){
    string n;
    int k;
    std::cin>>n>>k;
    std::cout<<superDigit(n, k);
    return 0;
}
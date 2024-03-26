#include <iostream>
using namespace std;
/*
 * Complete the 'twoStrings' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. STRING s1
 *  2. STRING s2
 */
// this function use hash tables in it

string twoStrings(string s1, string s2) {
    vector<char> charVec;

    for (int i = 0; i < s1.size(); i++) {
        charVec.push_back(s1[i]);
    }

    for (int i = 0; i < s2.size(); i++) {
        auto idx = find(charVec.begin(), charVec.end(), s2[i]);
        if (idx != charVec.end()) {
            return "YES";
        }
    }
    return "NO";
}
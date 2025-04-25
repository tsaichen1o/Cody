/**
 * @file 03_Palindrome.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2024-03-10
 * 
 * @copyright Copyright (c) 2024
 * 
 */

/*
這個方法只需要單個循環，並且使用兩個指針來比較字符串的字符。如果找到左右兩側的字符相等，就繼續移動指針；
如果找到不相等的字符，則返回-1。這種方法的時間複雜度為O(N)，其中N是字符串的長度。
*/
#include <string>

int solution(string &S) {
    int n = S.size();
    int left = 0;
    int right = n - 1;

    while (left < right) {
        if (S[left] == S[right]) {
            left++;
            right--;
        } else {
            return -1;
        }
    }

    return left - 1;
}

// solution 2

// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;
 
// Function to check whether
// the string is palindrome
string isPalindrome(string S)
{
    // Stores the reverse of the
    // string S
    string P = S;
 
    // Reverse the string P
    reverse(P.begin(), P.end());
    // TC: O(N)
 
    // If S is equal to P
    if (S == P) {
        // Return "Yes"
        return "Yes";
    }
    // Otherwise
    else {
        // return "No"
        return "No";
    }
}
 
// Driver Code
int main()
{
    string S = "ABCDCBA";
    cout << isPalindrome(S);
 
    return 0;
}

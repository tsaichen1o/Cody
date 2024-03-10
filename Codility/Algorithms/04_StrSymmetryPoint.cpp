/**
 * @file 04_StrSymmetryPoint.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief O(length(N)) 92% only
 * @version 0.1
 * @date 2024-03-10
 * 
 * @copyright Copyright (c) 2024
 * 
 */

// My attempt: failed for large size
#include <cstring>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(string &S) {
    long int tempCount = 0, n = 0;
    n = S.size();

    if (n > 1) {
        for (long int i = 1; i < n - 1; i++) {
            for (long int j = 1; j < n / 2 + 1; j++) {
                if (S[i - j] == S[i + j]) {
                    tempCount++;
                } else {
                    break;
                }
            }
        }
    } else if (n == 1) {
        tempCount = 0;
    } else {
        tempCount = -1;
    }

    return tempCount;
}

// solution 2
#include <string>

int solution(string &S) {
    // If the string has only one character, return 0
    if (S.size() == 1) {
        return 0;
    }
    
    if (S.size() % 2 == 0) {
        return -1;
    }
    
    long int left = 0, right = S.size() - 1;

    // Traverse the string from both ends
    while (left < right) {
        // Move left pointer to the right until it points to a different character
        while (left < right && S[left] == S[right]) {
            left++;
            right--;
        }

        // Check if the substring between left and right pointers is a palindrome
        bool isPalindrome = true;
        long int i = left, j = right;
        while (i < j) {
            if (S[i] != S[j]) {
                isPalindrome = false;
                break;
            }
            i++;
            j--;
        }

        // If the substring is a palindrome, return the current index
        if (isPalindrome) {
            return left;
        }

        // Move right pointer to the left and continue the search
        right--;
    }

    // If no such index exists, return -1
    return -1;
}
/**
 * @file [SS]2825.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 2825. Make String a Subsequence Using Cyclic Increments
 * @version 0.1
 * @date 2024-12-04
 * 
 * @copyright Copyright (c) 2024
 * 
 */

class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int j = 0;
        int str1Length = str1.length();
        int str2Length = str2.length();
        if (str1Length < str2Length) return false;

        for (int i = 0; i < str1Length && j < str2Length; i++) {
            char shiftedChar = (str1[i] == 'z') ? 'a' : str1[i] + 1;
            if (str1[i] == str2[j] || shiftedChar == str2[j]) {
                j++;
            }
        }

        return j == str2Length;
    }
};

// 100%
class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int j = 0;
        int str1Length = str1.length();
        int str2Length = str2.length();
        if (str1Length < str2Length) return false;

        for (int i = 0; i < str1Length && j < str2Length; i++) {
            // Check if character matches directly or after a shift.
            if (str1[i] == str2[j] || (str1[i] - 'a' + 1) % 26 + 'a' == str2[j]) {
                j++;
            }
        }

        return j == str2Length;
    }
};

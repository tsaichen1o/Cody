/**
 * @file [SS]0392.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 392. Is Subsequence
 * @version 0.1
 * @date 2024-12-04
 * 
 * @copyright Copyright (c) 2024
 * 
 */

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int j = 0;  // Pointer for string s

        // Traverse through string t
        for (int i = 0; i < t.length() && j < s.length(); i++) {
            if (t[i] == s[j]) {
                j++;  // Move pointer in s if characters match
            }
        }

        // If j equals the length of s, all characters are matched in order
        return j == s.length();
    }
};

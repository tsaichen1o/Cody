/**
 * @file [SS]0647.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 647. Palindromic Substrings
 * @version 0.1
 * @date 2024-11-26
 * 
 * @copyright Copyright (c) 2024
 * 
 */

class Solution {
public:
    int countSubstrings(string s) {
        int totalCount = 0; // Initialize count of palindromic substrings
        int length = s.size(); // Get the size of the input string

        // Iterate over the string, considering both odd and even length palindromes
        for (int center = 0; center < length * 2 - 1; ++center) {
            // For an odd-length palindrome, both i and j start at the same index.
            // For an even-length palindrome, j starts at the next index after i.
            int left = center / 2;
            int right = (center + 1) / 2;

            // Expand around the center as long as the characters are the same
            while (left >= 0 && right < length && s[left] == s[right]) {
                ++totalCount; // Increment the count for the current palindrome
                --left;  // Move the left pointer backward
                ++right; // Move the right pointer forward
            }
        }
        return totalCount; // Return the total count of palindromic substrings
    }
};
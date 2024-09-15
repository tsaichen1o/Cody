/**
 * @file 20240915_1371.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 1371. Find the Longest Substring Containing Vowels in Even Counts
 * @version 0.1
 * @date 2024-09-15
 * 
 * @copyright Copyright (c) 2024
 * 
 */

/*
Input: s = "eleetminicoworoep"
Output: 13
Explanation: The longest substring is "leetminicowor" which contains two each of the vowels: e, i and o and zero of the vowels: a and u.

Input: s = "leetcodeisgreat"
Output: 5
Explanation: The longest substring is "leetc" which contains two e's.
*/
class Solution {
public:
    int findTheLongestSubstring(string s) {
        int n = s.size();
        vector<int> firstOccurrence(32, -1);  // firstOccurrence[mask] stores the first occurrence of mask
        firstOccurrence[0] = 0;  // Empty string has even count of all vowels
        int mask = 0, maxLength = 0;
        
        for (int i = 0; i < n; i++) {
            if (s[i] == 'a') mask ^= 1;  // Toggle the 0-th bit
            else if (s[i] == 'e') mask ^= 2;  // Toggle the 1-st bit
            else if (s[i] == 'i') mask ^= 4;  // Toggle the 2-nd bit
            else if (s[i] == 'o') mask ^= 8;  // Toggle the 3-rd bit
            else if (s[i] == 'u') mask ^= 16;  // Toggle the 4-th bit
            
            if (firstOccurrence[mask] != -1) {
                maxLength = max(maxLength, i + 1 - firstOccurrence[mask]);
            } else {
                firstOccurrence[mask] = i + 1;
            }
        }
        
        return maxLength;
    }
};

// improved readibility
class Solution {
public:
    int findTheLongestSubstring(string s) {
        int n = s.size();
        vector<int> firstOccurrence(32, -1);  // 32 possible states for the bitmask
        firstOccurrence[0] = 0;  // Empty string (no vowels) has even counts of all vowels
        int mask = 0, maxLength = 0;

        for (int i = 0; i < n; i++) {
            // Toggle the corresponding bit for each vowel
            switch (s[i]) {
                case 'a': mask ^= 1; break;
                case 'e': mask ^= 2; break;
                case 'i': mask ^= 4; break;
                case 'o': mask ^= 8; break;
                case 'u': mask ^= 16; break;
            }

            // Check if we've seen this bitmask before
            if (firstOccurrence[mask] != -1) {
                maxLength = max(maxLength, i + 1 - firstOccurrence[mask]);
            } else {
                firstOccurrence[mask] = i + 1;  // Store the first occurrence of this bitmask
            }
        }

        return maxLength;
    }
};

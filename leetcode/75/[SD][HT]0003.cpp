/**
 * @file [SD][HT]0003.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 3. Longest Substring Without Repeating Characters
 * @version 0.1
 * @date 2024-11-26
 * https://leetcode.com/problems/longest-substring-without-repeating-characters
 * @copyright Copyright (c) 2024
 * 
 */

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxCount = 0;
        set<char> charCountSet; // Use set<char> to store characters
        int left = 0;

        // Sliding window approach
        for (int right = 0; right < s.size(); ++right) {
            while (charCountSet.count(s[right])) {
                charCountSet.erase(s[left]);
                left++;
            }
            charCountSet.insert(s[right]);
            maxCount = max(maxCount, right - left + 1);
        }

        return maxCount;
    }
};

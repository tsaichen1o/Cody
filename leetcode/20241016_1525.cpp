/**
 * @file 20241016_1525.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 1525. Number of Good Ways to Split a String
 * @version 0.1
 * @date 2024-10-16
 * 
 * @copyright Copyright (c) 2024
 * 
 */

class Solution {
public:
    int numSplits(string s) {
        unordered_map<char, int> countLeft, countRight;
        int n = s.size(), ans = 0;

        // Count the frequency of each character in the right side initially
        for (char c : s) {
            countRight[c]++;
        }

        // Track distinct character counts for left and right sides
        int distinctLeft = 0, distinctRight = countRight.size();

        for (int i = 0; i < n - 1; ++i) {
            char c = s[i];
            
            // Move character from right to left
            countLeft[c]++;
            if (countLeft[c] == 1) distinctLeft++;  // New distinct character in left
            
            countRight[c]--;
            if (countRight[c] == 0) distinctRight--;  // Remove character from right if count becomes zero
            
            // Check if the split is good
            if (distinctLeft == distinctRight) {
                ans++;
            }
        }

        return ans;
    }
};
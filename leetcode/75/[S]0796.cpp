/**
 * @file [S]0796.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2024-12-04
 * 796. Rotate String
 * @copyright Copyright (c) 2024
 * 
 */

class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.length() != goal.length()) {
            return false;
        }

        string doubled = s + s;  // Concatenate s with itself
        return doubled.find(goal) != string::npos;  // Check if goal is a substring of doubled
    }
};

// Time Complexity: O(n^2)
// Space Complexity: O(n)


/**
 * @file 20241103_0796.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 796. Rotate String
 * @version 0.1
 * @date 2024-11-03
 * 
 * @copyright Copyright (c) 2024
 * 
 */

class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.length() != goal.length()) {
            return false;
        }

        s += s; // Concatenate s with itself

        // Check if goal is a substring of the concatenated string
        return s.find(goal) != string::npos;
    }
};
/**
 * @file [TP]2337.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 2337. Move Pieces to Obtain a String
 * @version 0.1
 * @date 2024-12-05
 * 
 * @copyright Copyright (c) 2024
 * 
 */

class Solution {
public:
    bool canChange(string start, string target) {
        int i = 0, j = 0;
        const int n = start.length();

        while (i < n || j < n) {
            // Find the next non-underscore character in both strings
            while (i < n && start[i] == '_') ++i;
            while (j < n && target[j] == '_') ++j;

            // If either index reaches the end, they both must do so
            if (i == n || j == n)
                return i == n && j == n;

            // Check if the characters are different
            if (start[i] != target[j])
                return false;

            // Check if 'R' is moving to the left or 'L' is moving to the right (invalid moves)
            if ((start[i] == 'R' && i > j) || (start[i] == 'L' && i < j))
                return false;

            ++i;
            ++j;
        }

        return true;
    }
};


// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    bool canChange(const string& start, const string& target) {
        const int n = start.length();
        int startIndex = 0;  // Index for start string
        int targetIndex = 0; // Index for target string

        while (startIndex < n || targetIndex < n) {
            // Move startIndex and targetIndex to the next non-underscore character
            while (startIndex < n && start[startIndex] == '_')
                ++startIndex;
            while (targetIndex < n && target[targetIndex] == '_')
                ++targetIndex;

            // If either index reaches the end, both must do so for a match
            if (startIndex == n || targetIndex == n)
                return startIndex == n && targetIndex == n;

            // Check if the current characters are the same
            if (start[startIndex] != target[targetIndex])
                return false;

            // Rule for 'R': It can only move to the right, so it must not go backward
            if (start[startIndex] == 'R' && startIndex > targetIndex)
                return false;

            // Rule for 'L': It can only move to the left, so it must not go forward
            if (start[startIndex] == 'L' && startIndex < targetIndex)
                return false;

            // Move to the next character
            ++startIndex;
            ++targetIndex;
        }

        return true;
    }
};
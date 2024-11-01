/**
 * @file 20241101_1957.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 1957. Delete Characters to Make Fancy String
 * @version 0.1
 * @date 2024-11-01
 * 
 * @copyright Copyright (c) 2024
 * 
 */

class Solution {
public:
    string makeFancyString(string s) {
        string result;

        for (char c : s) {
            int n = result.size();
            // Only add the character if the last two characters are not the same as `c`
            if (n < 2 || !(result[n - 1] == c && result[n - 2] == c)) {
                result += c;
            }
        }

        return result;
    }
};

class Solution {
public:
    string makeFancyString(string s) {
        string result;
        int count = 1; // Track consecutive characters

        // Add the first character to the result to start
        result += s[0];

        // Iterate through s starting from the second character
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == s[i - 1]) {
                // If current char is the same as the previous, increase count
                count++;
            } else {
                // If it's a different character, reset count
                count = 1;
            }

            // Append to result only if count is less than 3
            if (count < 3) {
                result += s[i];
            }
        }

        return result;
    }
};
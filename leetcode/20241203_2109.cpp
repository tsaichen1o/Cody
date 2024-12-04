/**
 * @file 20241203_2109.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 2109. Adding Spaces to a String
 * @version 0.1
 * @date 2024-12-03
 * 
 * @copyright Copyright (c) 2024
 * 
 */

class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string res;
        int n = s.length(), m = spaces.size();
        int i = 0, j = 0;
        if (n == 0) return {};
        if (m == 0) return s;
        while (i < n) {
            if (j < m && (i == spaces[j])) {
                res += ' ';
                j++;
            } else {
                res += s[i];
                i++;
            }
        }

        return res;
    }
};
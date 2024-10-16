/**
 * @file 20241016_1736.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 1736. Latest Time by Replacing Hidden Digits
 * @version 0.1
 * @date 2024-10-16
 * 
 * @copyright Copyright (c) 2024
 * 
 */

class Solution {
public:
    string maximumTime(string time) {
        // Replace hour digits
        if (time[0] == '?') {
            time[0] = (time[1] == '?' || time[1] < '4') ? '2' : '1';
        }
        if (time[1] == '?') {
            time[1] = (time[0] == '2') ? '3' : '9';
        }

        // Replace minute digits
        if (time[3] == '?') {
            time[3] = '5';
        }
        if (time[4] == '?') {
            time[4] = '9';
        }

        return time;
    }
};

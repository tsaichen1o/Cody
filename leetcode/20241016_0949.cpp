/**
 * @file 20241016_0949.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 949. Largest Time for Given Digits
 * @version 0.1
 * @date 2024-10-16
 * 
 * @copyright Copyright (c) 2024
 * 
 */

class Solution {
public:
    string largestTimeFromDigits(vector<int>& arr) {
        string result = "";
        sort(arr.begin(), arr.end());

        do {
            int hours = arr[0] * 10 + arr[1];
            int minutes = arr[2] * 10 + arr[3];

            if (hours < 24 && minutes < 60) {
                string current = to_string(arr[0]) + to_string(arr[1]) + ":" +
                                 to_string(arr[2]) + to_string(arr[3]);
                
                if (result.empty() || current > result) {
                    result = current;
                }
            }
        } while (next_permutation(arr.begin(), arr.end()));

        return result;
    }
};

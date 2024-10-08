/**
 * @file 20241008_1963.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 1963. Minimum Number of Swaps to Make the String Balanced
 * @version 0.1
 * @date 2024-10-08
 * 
 * @copyright Copyright (c) 2024
 * 
 */

class Solution {
public:
    int minSwaps(string s) {
        int n = s.size();
        int balance = 0;
        int swaps = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '[') {
                balance++;
            } else {
                balance--;
                if (balance < 0) {
                    swaps++;
                    balance = 1;
                }
            }
        }
        return swaps;
    }
};
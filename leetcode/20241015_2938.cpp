/**
 * @file 20241015_2938.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 2938. Separate Black and White Balls
 * @version 0.1
 * @date 2024-10-15
 * 
 * @copyright Copyright (c) 2024
 * 
 */

class Solution {
public:
    long long minimumSteps(string s) {
        long long ans = 0;
        int zeroCount = 0;  // Track number of '0's seen

        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == '0') {
                zeroCount++;  // Increment count of '0's
            } else {
                ans += zeroCount;  // Each '1' needs to swap with all '0's to its right
            }
        }

        return ans;
    }
};

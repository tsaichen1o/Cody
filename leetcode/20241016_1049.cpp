/**
 * @file 20241016_1049.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 1049. Last Stone Weight II
 * @version 0.1
 * @date 2024-10-16
 * 
 * @copyright Copyright (c) 2024
 * 
 */

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int total_sum = accumulate(stones.begin(), stones.end(), 0);
        int target = total_sum / 2;

        // DP array to track achievable subset sums up to target
        vector<bool> dp(target + 1, false);
        dp[0] = true;

        // Update dp array with each stone
        for (int stone : stones) {
            for (int j = target; j >= stone; --j) {
                dp[j] = dp[j] || dp[j - stone];
            }
        }

        // Find the largest achievable sum closest to target
        for (int i = target; i >= 0; --i) {
            if (dp[i]) {
                return total_sum - 2 * i;
            }
        }

        return 0; // In case no valid configuration is found (shouldn't happen with valid input)
    }
};
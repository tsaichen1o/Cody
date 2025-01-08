/**
 * @file [DP]0198.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 198. House Robber
 * @version 0.1
 * @date 2024-12-01
 * 
 * @copyright Copyright (c) 2024
 * 
 */

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        // Variables to store the maximum amounts for two scenarios:
        int prev2 = 0; // Represents the maximum amount up to two houses ago.
        int prev1 = nums[0]; // Represents the maximum amount up to the previous house.

        // Iterate through the houses to determine maximum rob amount
        for (int i = 1; i < n; i++) {
            int current = max(prev1, prev2 + nums[i]);
            prev2 = prev1;
            prev1 = current;
        }

        return prev1;
    }
};
// Time Complexity: O(n)
// Space Complexity: O(1)


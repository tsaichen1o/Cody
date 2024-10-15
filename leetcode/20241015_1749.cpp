/**
 * @file 20241015_1749.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 1749. Maximum Absolute Sum of Any Subarray
 * @version 0.1
 * @date 2024-10-15
 * 
 * @copyright Copyright (c) 2024
 * 
 */

class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxSum = nums[0], minSum = nums[0];
        int currentMax = 0, currentMin = 0;

        for (int num : nums) {
            // For maximum subarray sum
            currentMax = max(num, currentMax + num);
            maxSum = max(maxSum, currentMax);

            // For minimum subarray sum
            currentMin = min(num, currentMin + num);
            minSum = min(minSum, currentMin);
        }

        // Maximum of the absolute values of maxSum and minSum
        return max(abs(maxSum), abs(minSum));
    }
};
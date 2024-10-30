/**
 * @file 20241030_1671.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 1671. Minimum Number of Removals to Make Mountain Array
 * @version 0.1
 * @date 2024-10-30
 * https://algo.monster/liteproblems/1671
 * @copyright Copyright (c) 2024
 * 
 */

class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int size = nums.size();
        vector<int> left(size, 1), right(size, 1); // Initialize LIS vectors for left and right

        // Compute the length of longest increasing subsequence (LIS) from the left
        for (int i = 1; i < size; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    left[i] = max(left[i], left[j] + 1); // Update the LIS at i based on j
                }
            }
        }

        // Compute the length of LIS from the right
        for (int i = size - 2; i >= 0; --i) {
            for (int j = i + 1; j < size; ++j) {
                if (nums[i] > nums[j]) {
                    right[i] = max(right[i], right[j] + 1); // Update the LIS at i based on j
                }
            }
        }

        int maxMountainLength = 0; // Variable to keep track of the longest mountain length

        // Find the maximum length of a bitonic subsequence (peak of the mountain)
        for (int i = 0; i < size; ++i) {
            // Ensure we have an increasing and decreasing subsequence, i.e., a peak
            if (left[i] > 1 && right[i] > 1) {
                // Update the maxMountainLength if left[i] + right[i] - 1 is greater
                maxMountainLength = max(maxMountainLength, left[i] + right[i] - 1);
            }
        }

        // The minimum removals will be the total number of elements minus the longest mountain length
        return size - maxMountainLength;
    }
};
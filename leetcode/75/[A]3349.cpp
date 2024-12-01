/**
 * @file [A]3349.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 3349. Adjacent Increasing Subarrays Detection I
 * @version 0.1
 * @date 2024-12-01
 * 
 * @copyright Copyright (c) 2024
 * 
 */

class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        
        if (n < 2 * k) {
            // If the length of nums is less than 2 * k, it is not possible to have two adjacent subarrays of length k
            return false;
        }

        // Check if there are two adjacent strictly increasing subarrays of length k
        for (int i = 0; i <= n - 2 * k; ++i) {
            bool firstIncreasing = true, secondIncreasing = true;

            // Check if the first subarray (from index i to i + k - 1) is strictly increasing
            for (int j = i; j < i + k - 1; ++j) {
                if (nums[j] >= nums[j + 1]) {
                    firstIncreasing = false;
                    break;
                }
            }

            // If the first subarray is not strictly increasing, skip checking the second subarray
            if (!firstIncreasing) continue;

            // Check if the second subarray (from index i + k to i + 2 * k - 1) is strictly increasing
            for (int j = i + k; j < i + 2 * k - 1; ++j) {
                if (nums[j] >= nums[j + 1]) {
                    secondIncreasing = false;
                    break;
                }
            }

            // If both subarrays are strictly increasing, return true
            if (firstIncreasing && secondIncreasing) {
                return true;
            }
        }

        // If no such two adjacent strictly increasing subarrays of length k are found, return false
        return false;
    }
};


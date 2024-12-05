/**
 * @file [TP]1099.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 1099. Two Sum Less Than K
 * @version 0.1
 * @date 2024-12-05
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <vector>
#include <algorithm>

class Solution {
public:
    int twoSumLessThanK(std::vector<int>& nums, int k) {
        std::sort(nums.begin(), nums.end());  // Sort the array
        int left = 0;
        int right = nums.size() - 1;
        int maxSum = -1;

        // Use two pointers to find the maximum sum < k
        while (left < right) {
            int sum = nums[left] + nums[right];
            if (sum < k) {
                maxSum = std::max(maxSum, sum);
                left++;
            } else {
                right--;
            }
        }

        return maxSum;
    }
};

// Time Complexity: O(nlogn), where n is the length of the input array.
// Space Complexity: O(1), as it uses constant extra space.
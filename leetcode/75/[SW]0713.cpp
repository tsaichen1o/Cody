/**
 * @file [SW]0713.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 713. Subarray Product Less Than K
 * @version 0.1
 * @date 2024-12-05
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <vector>

class Solution {
public:
    int numSubarrayProductLessThanK(std::vector<int>& nums, int k) {
        if (k <= 1) return 0;

        int left = 0;
        int product = 1;
        int count = 0;

        for (int right = 0; right < nums.size(); ++right) {
            product *= nums[right];
            // Slide the left pointer until the product is less than k
            while (product >= k) {
                product /= nums[left++];
            }
            // All subarrays ending at `right` with a starting index from `left` to `right`
            count += right - left + 1;
        }

        return count;
    }
};

/**
 * @file [BS]1060.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 1060. Missing Element in Sorted Array
 * @version 0.1
 * @date 2024-12-01
 * 
 * @copyright Copyright (c) 2024
 * 
 */

class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        // Calculate how many elements are missing until index i.
        auto countMissingUpToIndex = [&](int index) {
            return nums[index] - nums[0] - index;
        };

        int n = nums.size();
      
        // If k is greater than the number of missing elements up to the last element,
        // calculate and return the result directly.
        if (k > countMissingUpToIndex(n - 1)) {
            return nums[n - 1] + k - countMissingUpToIndex(n - 1);
        }

        // Binary search between indices 0 and n-1.
        int left = 0, right = n - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (countMissingUpToIndex(mid) < k) {
                left = mid + 1;  // Move right to find more missing elements.
            } else {
                right = mid;  // Move left to find the smallest index where missing count is >= k.
            }
        }

        // Calculate the k-th missing number using the left index.
        return nums[left - 1] + k - countMissingUpToIndex(left - 1);
    }
    int countMissingUpToIndex(const std::vector<int>& nums, int index) {
        return nums[index] - nums[0] - index;
    }
};

// Time Complexity: O(log(n))
// Space Complexity: O(1)
/**
 * @file [SW]0259.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 259. 3Sum Smaller
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
    int threeSumSmaller(std::vector<int>& nums, int target) {
        int n = nums.size();
        if (n < 3) return 0;

        std::sort(nums.begin(), nums.end());
        int count = 0;

        for (int i = 0; i < n - 2; ++i) {
            for (int j = i + 1; j < n - 1; ++j) {
                int two_sum = nums[i] + nums[j];
                int remaining = target - two_sum;
                
                // Use binary search to find the maximum index 'k' such that nums[k] < remaining.
                int left = j + 1, right = n - 1;
                while (left <= right) {
                    int mid = left + (right - left) / 2;
                    if (nums[mid] < remaining) {
                        left = mid + 1;
                    } else {
                        right = mid - 1;
                    }
                }
                count += left - (j + 1);
            }
        }

        return count;
    }
};

// Time Complexity: O(n^2logn), where n is the length of the input array.
// Space Complexity: O(1), as it uses constant extra space.

#include <vector>
#include <algorithm>

class Solution {
public:
    int threeSumSmaller(std::vector<int>& nums, int target) {
        int n = nums.size();
        if (n < 3) return 0;

        std::sort(nums.begin(), nums.end());
        int count = 0;

        // Iterate through the array
        for (int i = 0; i < n - 2; ++i) {
            int left = i + 1;
            int right = n - 1;

            // Use two pointers to find the valid triplets
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum < target) {
                    // Since nums is sorted, all combinations between left and right will also satisfy the condition.
                    count += right - left;
                    ++left;
                } else {
                    --right;
                }
            }
        }

        return count;
    }
};

// Time Complexity: O(n^2), where n is the length of the input array.
// Space Complexity: O(1), as it uses constant extra space.
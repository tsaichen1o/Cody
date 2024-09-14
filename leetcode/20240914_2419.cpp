/**
 * @file 20240914_2419.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 2419. Longest Subarray With Maximum Bitwise AND
 * @version 0.1
 * @date 2024-09-14
 * 
 * @copyright Copyright (c) 2024
 * 
 */

/*
You are given an integer array nums of size n.

Consider a non-empty subarray from nums that has the maximum possible bitwise AND.

In other words, let k be the maximum value of the bitwise AND of any subarray of nums. Then, only subarrays with a bitwise AND equal to k should be considered.
Return the length of the longest such subarray.

The bitwise AND of an array is the bitwise AND of all the numbers in it.

A subarray is a contiguous sequence of elements within an array.
*/

// Notice that the bitwise AND of two different numbers will always be strictly less than the maximum of those two numbers.


class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int count = 0, maxAND = 0, currentMaxAND = 0;
        maxAND = nums[0];
        currentMaxAND = nums[0];
        
        for (int i = 0; i < n; i++) {
            currentMaxAND = max(nums[i], currentMaxAND & nums[i]);
            maxAND = max(maxAND, currentMaxAND);
        }

        
        return count;
    }
};

// 
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxAND = *max_element(nums.begin(), nums.end());  // Find the maximum value in the array
        int maxLength = 0, currentLength = 0;

        for (int num : nums) {
            if (num == maxAND) {
                // If current number is equal to maxAND, increase the current subarray length
                currentLength++;
                maxLength = max(maxLength, currentLength);
            } else {
                // If the number is not equal to maxAND, reset current subarray length
                currentLength = 0;
            }
        }

        return maxLength;
    }
};

/**
 * @file 20241014_0034.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 34. Find First and Last Position of Element in Sorted Array
 * @version 0.1
 * @date 2024-10-14
 * 
 * @copyright Copyright (c) 2024
 * 
 */

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int firstIdx = -1, lastIdx = -1;
        
        // find first index
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                firstIdx = mid;
                right = mid - 1;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        left = 0;
        right = nums.size() - 1;
        // find last index
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                lastIdx = mid;
                left = mid + 1;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return {firstIdx, lastIdx};
    }
};


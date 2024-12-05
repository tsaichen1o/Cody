/**
 * @file [TP]0167.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 167. Two Sum II - Input Array Is Sorted
 * @version 0.1
 * @date 2024-12-05
 * 
 * @copyright Copyright (c) 2024
 * 
 */

class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        int l = 0;
        int r = arr.size() - 1;
        while (l < r) {
            int two_sum = arr[l] + arr[r];
            if (two_sum == target) {
                return {l + 1, r + 1};
            } else if (two_sum < target) {
                l++;
            } else {
                r--;
            }
        }
        return {};
    }
};

// Time Complexity: O(n), where n is the length of the input array.
// Space Complexity: O(1), as it uses constant extra space.
/**
 * @file 20241014_0540.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 540. Single Element in a Sorted Array
 * @version 0.1
 * @date 2024-10-14
 * 
 * @copyright Copyright (c) 2024
 * 
 */

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0, right = nums.size() - 1, ans = -1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (to_the_left(nums, mid)) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return nums[ans];
    }

private:
    bool to_the_left(vector<int>& nums, int idx) {
        if (idx == nums.size() - 1) return true;
        else if (idx % 2 == 1) return nums[idx] != nums[idx - 1];
        else return nums[idx] != nums[idx + 1];
    }
};

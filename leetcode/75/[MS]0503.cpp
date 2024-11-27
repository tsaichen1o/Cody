/**
 * @file [MS]0503.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 503. Next Greater Element II
 * @version 0.1
 * @date 2024-11-25
 * https://leetcode.com/problems/next-greater-element-ii/
 * @copyright Copyright (c) 2024
 * 
 */

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> stack;
        vector<int> res(nums.size(), -1);

        for (int i = 0; i < nums.size(); i++) {
            while (!stack.empty() && nums[i] > nums[stack.back()]) {
                res[stack.back()] = nums[i];
                stack.pop_back();
            }
            stack.emplace_back(i);
        }
        for (int num : nums) {
            while (num > nums[stack.back()]) {
                res[stack.back()] = num;
                stack.pop_back();
            }
        }
        return res;
    }
};
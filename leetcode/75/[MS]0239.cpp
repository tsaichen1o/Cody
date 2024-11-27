/**
 * @file [MS]0239.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 239. Sliding Window Maximum
 * @version 0.1
 * @date 2024-11-25
 * https://leetcode.com/problems/sliding-window-maximum/description/
 * https://algo.monster/problems/sliding_window_maximum
 * @copyright Copyright (c) 2024
 * 
 */

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> max_indices;
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            while (!max_indices.empty() &&
                   nums[max_indices.back()] <= nums[i]) {
                max_indices.pop_back();
            }
            max_indices.push_back(i);
            // remove first element if it's outside the window
            if (max_indices.front() == i - k) {
                max_indices.pop_front();
            }
            // if window has k elements add to results (first k-1 windows have <
            // k elements because we start from empty window and add 1 element
            // each iteration)
            if (i >= k - 1) {
                res.emplace_back(nums[max_indices.front()]);
            }
        }
        return res;
    }
};
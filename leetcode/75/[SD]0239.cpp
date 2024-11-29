/**
 * @file [SD]0239.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 239. Sliding Window Maximum
 * @version 0.1
 * @date 2024-11-27
 * 
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

// TLE
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        int n = nums.size();

        // Traverse the array with a sliding window of size `k`
        for (int i = 0; i <= n - k; ++i) {
            // Get the maximum in the current window
            int max_val = *max_element(nums.begin() + i, nums.begin() + i + k);
            result.push_back(max_val);
        }

        return result;
    }
};

vector<int> findMaxInSlidingWindow(vector<int> nums, int windowSize) {
    deque<int> dequeIndices; // Stores indices of elements that are candidates for max
    vector<int> result;

    for (int i = 0; i < nums.size(); i++) {
        // Remove elements from the back of the deque that are smaller than the current element
        while (!dequeIndices.empty() && nums[dequeIndices.back()] <= nums[i]) {
            dequeIndices.pop_back();
        }

        // Add the current index to the deque
        dequeIndices.push_back(i);

        // Remove the element from the front if it's outside the current sliding window
        if (dequeIndices.front() == i - windowSize) {
            dequeIndices.pop_front();
        }

        // Add the maximum value for the current window to the result
        if (i >= windowSize - 1) {
            result.push_back(nums[dequeIndices.front()]);
        }
    }

    return result;
}

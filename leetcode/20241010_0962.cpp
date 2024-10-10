/**
 * @file 20241010_0962.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 962. Maximum Width Ramp
 * @version 0.1
 * @date 2024-10-10
 * 
 * @copyright Copyright (c) 2024
 * 
 */

class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        for (int i = 0; i < n; ++i) {
            if (st.empty() || nums[i] < nums[st.top()]) {
                st.push(i);
            }
        }
        
        int maxWidth = 0;
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && nums[i] >= nums[st.top()]) {
                maxWidth = max(maxWidth, i - st.top());
                st.pop();
            }
        }
        
        return maxWidth;
    }
};


// 
class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        
        // Populate the stack with potential starting indices
        for (int i = 0; i < n; ++i) {
            if (st.empty() || nums[i] < nums[st.top()]) {
                st.push(i);
            }
        }
        
        int maxWidth = 0;
        
        // Iterate from the end to the start, calculating ramp width
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && nums[i] >= nums[st.top()]) {
                maxWidth = max(maxWidth, i - st.top());
                st.pop();
            }
        }
        
        return maxWidth;
    }
};

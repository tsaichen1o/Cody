/**
 * @file 20241017_0300.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 300. Longest Increasing Subsequence
 * @version 0.1
 * @date 2024-10-17
 * 
 * @copyright Copyright (c) 2024
 * 
 */

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1, numeric_limits<int>::max());
        dp[0] = numeric_limits<int>::min();

        for (int i = 0; i < n; i++) {
            int j = upper_bound(dp.begin(), dp.end(), nums[i]) - dp.begin();
            if (dp[j - 1] < nums[i] && nums[i] < dp[j]) {
                dp[j] = nums[i];
            }
        }

        int ans = 0;
        for (int i = 0; i <= n; i++) {
            if (dp[i] < numeric_limits<int>::max()) {
                ans = i;
            }
        }
        return ans;
    }
};
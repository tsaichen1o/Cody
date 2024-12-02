/**
 * @file [DP]0276.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 276. Paint Fence
 * @version 0.1
 * @date 2024-12-01
 * 
 * @copyright Copyright (c) 2024
 * 
 */

class Solution {
public:
    int numWays(int n, int k) {
        // Check for the base case where no fence posts are to be painted
        if (n == 0) {
            return 0;
        }

        // Initialize dynamic programming table with two columns:
        // dp[post][0] is the number of ways to paint the post such that it's a different color than the previous one
        // dp[post][1] is the number of ways to paint the post the same color as the previous one
        std::vector<std::vector<int>> dp(n, std::vector<int>(2));
      
        // Base case: Only one way to paint the first post with k different colors
        dp[0][0] = k;
      
        // Fill the dp table
        for (int post = 1; post < n; ++post) {
            // The number of ways to paint the current post a different color than the previous post
            // is the sum of the ways to paint the previous post (either same or different color)
            // times the number of colors left (k - 1)
            dp[post][0] = (dp[post - 1][0] + dp[post - 1][1]) * (k - 1);

            // The number of ways to paint the current post the same color as the previous post 
            // is the number of ways the previous post was painted with a different color than its previous one
            // Important: This is limited to one choice to ensure we don't break the rule of not having more than two
            // adjacent posts with the same color.
            dp[post][1] = dp[post - 1][0];
        }

        // Return the sum of the two possibilities for the last fence post
        return dp[n - 1][0] + dp[n - 1][1];
    }
};
/**
 * @file [DP]0256.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 256. Paint House
 * @version 0.1
 * @date 2024-12-01
 * 
 * @copyright Copyright (c) 2024
 * 
 */

class Solution {
public:
    // Function to calculate the minimum cost of painting houses.
    // No two adjacent houses can have the same color.
    int minCost(vector<vector<int>>& costs) {
        // Initialize the minimum costs of the last house for 
        // each color to be zero.
        int lastRed = 0, lastGreen = 0, lastBlue = 0;

        // Iterate over each house.
        for (auto& cost : costs) {
            // Store the previous costs before updating.
            int prevRed = lastRed, prevGreen = lastGreen, prevBlue = lastBlue;
          
            // Update the minimum cost for the current house when painted red.
            // It is the cost of painting the current house red plus the 
            // minimum cost of the previous house when it was not red.
            lastRed = min(prevGreen, prevBlue) + cost[0];
          
            // Update the minimum cost for the current house when painted green.
            // It is the cost of painting the current house green plus the 
            // minimum cost of the previous house when it was not green.
            lastGreen = min(prevRed, prevBlue) + cost[1];
          
            // Update the minimum cost for the current house when painted blue.
            // It is the cost of painting the current house blue plus the 
            // minimum cost of the previous house when it was not blue.
            lastBlue = min(prevRed, prevGreen) + cost[2];
        }

        // After considering all houses, return the minimum of the costs
        // of painting the last house with any of the three colors.
        return min(lastRed, min(lastGreen, lastBlue));
    }
};

// dp
class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        if (costs.empty()) return 0;

        int n = costs.size();
        vector<vector<int>> dp(n, vector<int>(3, 0));
        
        // Initialize the cost of painting the first house
        dp[0][0] = costs[0][0];
        dp[0][1] = costs[0][1];
        dp[0][2] = costs[0][2];
        
        // Iterate over each house and calculate the minimum cost for each color
        for (int i = 1; i < n; ++i) {
            dp[i][0] = costs[i][0] + min(dp[i-1][1], dp[i-1][2]);
            dp[i][1] = costs[i][1] + min(dp[i-1][0], dp[i-1][2]);
            dp[i][2] = costs[i][2] + min(dp[i-1][0], dp[i-1][1]);
        }
        
        // The result will be the minimum cost of painting the last house with any color
        return min(dp[n-1][0], min(dp[n-1][1], dp[n-1][2]));
    }
};

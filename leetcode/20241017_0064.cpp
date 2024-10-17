/**
 * @file 20241017_0064.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 64. Minimum Path Sum
 * @version 0.1
 * @date 2024-10-17
 * 
 * @copyright Copyright (c) 2024
 * 
 */

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n));
        dp[0][0] = grid[0][0];

        // Minimum path sum for the first row
        for (int c = 1; c < n; c++) {
            dp[0][c] = dp[0][c - 1] + grid[0][c];
        }

        // Minimum path sum for the first column
        for (int r = 1; r < m; r++) {
            dp[r][0] = dp[r - 1][0] + grid[r][0];
        }

        // Calculate minimum path sum for other cells
        for (int r = 1; r < m; r++) {
            for (int c = 1; c < n; c++) {
                dp[r][c] = min(dp[r - 1][c], dp[r][c - 1]) + grid[r][c];
            }
        }
        return dp[m - 1][n - 1];
    }
};
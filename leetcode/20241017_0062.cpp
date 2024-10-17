/**
 * @file 20241017_0062.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 62. Unique Paths
 * @version 0.1
 * @date 2024-10-17
 * https://leetcode.com/problems/unique-paths/
 * @copyright Copyright (c) 2024
 * 
 */

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(n, vector<int>(m));
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                if (row == 0 || col == 0) {
                    dp[row][col] = 1;
                } else {
                    dp[row][col] = dp[row][col - 1] + dp[row - 1][col];
                }
            }
        }
        return dp[n - 1][m - 1];
    }
};
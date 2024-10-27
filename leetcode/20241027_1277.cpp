/**
 * @file 20241027_1277.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 1277. Count Square Submatrices with All Ones
 * @version 0.1
 * @date 2024-10-27
 * https://algo.monster/liteproblems/1277
 * @copyright Copyright (c) 2024
 * 
 */

class Solution {
   public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();  // dimensions for matrix
        int ans = 0;
        vector<vector<int>> dp(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 || j == 0) {  // cell is in first row or column
                    dp[i][j] = matrix[i][j];
                } else if (matrix[i][j] == 1) {
                    dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
                }
                ans += dp[i][j];
            }
        }
        return ans;
    }
};
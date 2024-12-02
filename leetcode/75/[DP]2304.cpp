/**
 * @file [DP]2304.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 2304. Minimum Path Cost in a Grid
 * @version 0.1
 * @date 2024-12-01
 * 
 * @copyright Copyright (c) 2024
 * 
 */

class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int m = grid.size();
        int n = grid[0].size();
        // Initialize a vector to store the minimum cost to reach each cell in the current row
        vector<int> dp(grid[0].begin(), grid[0].end());

        // Iterate through each row, starting from the second row
        for (int i = 1; i < m; ++i) {
            vector<int> newDp(n, INT_MAX); // Temporary vector to store the new costs for the current row
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    // Calculate the cost to move from cell (i-1, j) to cell (i, k)
                    int cost = dp[j] + moveCost[grid[i-1][j]][k] + grid[i][k];
                    newDp[k] = min(newDp[k], cost);
                }
            }
            dp = newDp; // Update dp with the new costs for the current row
        }

        // Find the minimum cost to reach any cell in the last row
        return *min_element(dp.begin(), dp.end());
    }
};

/**
 * @file [DP]0688.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 688. Knight Probability in Chessboard
 * @version 0.1
 * @date 2024-12-04
 * 
 * @copyright Copyright (c) 2024
 * 
 */

class Solution {
public:
    double knightProbability(int n, int k, int row, int column) {
        // Possible 8 moves of a knight on a chessboard
        vector<pair<int, int>> moves = {
            {-2, -1}, {-1, -2}, {1, -2}, {2, -1},
            {2, 1}, {1, 2}, {-1, 2}, {-2, 1}
        };

        // Define a 3D DP table, with size (k+1) x n x n
        vector<vector<vector<double>>> dp(k + 1, vector<vector<double>>(n, vector<double>(n, 0.0)));
        
        // The initial probability for staying in the starting position is 1
        dp[0][row][column] = 1.0;

        // Iterate for every move from 1 to k
        for (int step = 1; step <= k; step++) {
            for (int r = 0; r < n; r++) {
                for (int c = 0; c < n; c++) {
                    if (dp[step - 1][r][c] > 0) {
                        for (auto& move : moves) {
                            int newRow = r + move.first;
                            int newCol = c + move.second;

                            // Check if new position is on board
                            if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < n) {
                                // Accumulate the probability
                                dp[step][newRow][newCol] += dp[step - 1][r][c] / 8.0;
                            }
                        }
                    }
                }
            }
        }

        // Calculate total probability after k moves by summing up all possible positions
        double totalProbability = 0.0;
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                totalProbability += dp[k][r][c];
            }
        }

        return totalProbability;
    }
};


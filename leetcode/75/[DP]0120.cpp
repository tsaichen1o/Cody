/**
 * @file [DP]0120.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 120. Triangle
 * @version 0.1
 * @date 2024-12-02
 * 
 * @copyright Copyright (c) 2024
 * 
 */

class Solution {
public:
    int dfs(std::vector<std::vector<int>>& triangle, int level, int column, std::vector<std::vector<int>>& memo) {
    if (level == triangle.size()) return 0;
    if (memo[level][column] != std::numeric_limits<int>::max()) {
        return memo[level][column];
    }
    int left = dfs(triangle, level + 1, column, memo);
    int right = dfs(triangle, level + 1, column + 1, memo);
    memo[level][column] = std::min(left, right) + triangle[level][column];
    return memo[level][column];
}

int minimumTotal(std::vector<std::vector<int>> triangle) {
    int n = triangle.size();
    std::vector<std::vector<int>> memo(n, std::vector<int>(n, std::numeric_limits<int>::max()));
    return dfs(triangle, 0, 0, memo);
}

};

// TLE
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        return min_path_sum(triangle, 0, 0);
    }
    
private:
    int min_path_sum(vector<vector<int>>& triangle, int row, int col) {
        if (row == triangle.size()) {
            return 0;
        }
        int left_sum = min_path_sum(triangle, row + 1, col);
        int right_sum = min_path_sum(triangle, row + 1, col + 1);
        return triangle[row][col] + min(left_sum, right_sum);
    }
};

class Solution {
public:
    int minimumTotal(std::vector<std::vector<int>>& triangle) {
        int n = triangle.size();

        std::vector<std::vector<int>> dp(n + 1, std::vector<int>(n + 1, 0));

        for (int i = 0; i < n; i++) { // first deal with last row
            dp[n - 1][i] = triangle[n - 1][i];
        }

        for (int i = n - 2; i >= 0;
             i--) { // start from second last row and build up to (0, 0)
            for (int j = 0; j <= i; j++) {
                dp[i][j] =
                    std::min(dp[i + 1][j], dp[i + 1][j + 1]) + triangle[i][j];
            }
        }

        return dp[0][0];
    }
};
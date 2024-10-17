/**
 * @file 20241017_0120.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 120. Triangle
 * @version 0.1
 * @date 2024-10-17
 * 
 * @copyright Copyright (c) 2024
 * 
 */

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> memo(n, vector<int>(n, -1)); // Initialize a memo table with -1
        return min_path_sum(triangle, 0, 0, memo);
    }
    
private:
    int min_path_sum(vector<vector<int>>& triangle, int row, int col, vector<vector<int>>& memo) {
        if (row == triangle.size()) {
            return 0;
        }
        if (memo[row][col] != -1) {
            return memo[row][col];
        }
        int left_sum = min_path_sum(triangle, row + 1, col, memo);
        int right_sum = min_path_sum(triangle, row + 1, col + 1, memo);
        memo[row][col] = triangle[row][col] + min(left_sum, right_sum);
        return memo[row][col];
    }
};

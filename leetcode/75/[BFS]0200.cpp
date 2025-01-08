/**
 * @file [BFS]0200.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 200. Number of Islands
 * @version 0.1
 * @date 2024-12-04
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <vector>
#include <queue>

class Solution {
public:
    int numIslands(std::vector<std::vector<char>>& grid) {
        int num_rows = grid.size();
        int num_cols = grid[0].size();
        int count = 0;

        for (int r = 0; r < num_rows; ++r) {
            for (int c = 0; c < num_cols; ++c) {
                if (grid[r][c] == '1') {
                    bfs(grid, r, c, num_rows, num_cols);
                    count++;
                }
            }
        }
        return count;
    }

private:
    void bfs(std::vector<std::vector<char>>& grid, int r, int c, int num_rows, int num_cols) {
        std::queue<std::pair<int, int>> q;
        q.push({r, c});
        grid[r][c] = '0';  // Mark cell as visited
        
        // Direction vectors for moving up, right, down, left
        std::vector<int> delta_row = {-1, 0, 1, 0};
        std::vector<int> delta_col = {0, 1, 0, -1};

        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop();

            for (int i = 0; i < 4; ++i) {
                int neighbor_row = row + delta_row[i];
                int neighbor_col = col + delta_col[i];
                
                // If the neighbor is within bounds and has value '1'
                if (neighbor_row >= 0 && neighbor_row < num_rows &&
                    neighbor_col >= 0 && neighbor_col < num_cols &&
                    grid[neighbor_row][neighbor_col] == '1') {
                    q.push({neighbor_row, neighbor_col});
                    grid[neighbor_row][neighbor_col] = '0';  // Mark as visited
                }
            }
        }
    }
};

// Time Complexity: O(m * n) where m is the number of rows and n is the number of columns in the grid
// Space Complexity: O(min(m, n)) for the queue in the BFS approach

// DFS solution
#include <vector>

class Solution {
public:
    int numIslands(std::vector<std::vector<char>>& grid) {
        int num_rows = grid.size();
        int num_cols = grid[0].size();
        int count = 0;

        // Iterate through every cell in the grid
        for (int r = 0; r < num_rows; ++r) {
            for (int c = 0; c < num_cols; ++c) {
                // If the cell is land ('1'), perform DFS
                if (grid[r][c] == '1') {
                    dfs(grid, r, c, num_rows, num_cols);
                    count++; // Increase count for each connected component
                }
            }
        }

        return count;
    }

private:
    void dfs(std::vector<std::vector<char>>& grid, int r, int c, int num_rows, int num_cols) {
        // Boundary check and check if the cell is water ('0')
        if (r < 0 || r >= num_rows || c < 0 || c >= num_cols || grid[r][c] == '0') {
            return;
        }

        // Mark the cell as visited
        grid[r][c] = '0';

        // Recursively call dfs on the neighboring cells (up, right, down, left)
        dfs(grid, r - 1, c, num_rows, num_cols); // up
        dfs(grid, r + 1, c, num_rows, num_cols); // down
        dfs(grid, r, c - 1, num_rows, num_cols); // left
        dfs(grid, r, c + 1, num_rows, num_cols); // right
    }
};

// Time Complexity: O(m * n) where m is the number of rows and n is the number of columns in the grid
// Space Complexity: O(m * n) for the recursive call stack in the DFS approach
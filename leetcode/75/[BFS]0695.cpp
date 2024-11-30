/**
 * @file [BFS]0695.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 695. Max Area of Island
 * @version 0.1
 * @date 2024-11-30
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <vector>
#include <queue>

class Solution {
public:
    int maxAreaOfIsland(std::vector<std::vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        int directions[5] = {-1, 0, 1, 0, -1};
        int maxArea = 0;

        // Iterate through every cell in the grid
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                // Start BFS if we find an unvisited land cell (i.e., grid[i][j] == 1)
                if (grid[i][j] == 1) {
                    int area = 0;
                    std::queue<std::pair<int, int>> q;
                    q.push({i, j});
                    grid[i][j] = 0; // Mark the cell as visited

                    while (!q.empty()) {
                        auto [x, y] = q.front();
                        q.pop();
                        area++; // Increase the area for each land cell visited

                        // Explore all four possible directions
                        for (int d = 0; d < 4; ++d) {
                            int newX = x + directions[d];
                            int newY = y + directions[d + 1];

                            // Check if the new position is within bounds and is a land cell
                            if (newX >= 0 && newX < rows && newY >= 0 && newY < cols && grid[newX][newY] == 1) {
                                q.push({newX, newY});
                                grid[newX][newY] = 0; // Mark as visited
                            }
                        }
                    }

                    // Update maxArea if a larger area is found
                    maxArea = std::max(maxArea, area);
                }
            }
        }

        return maxArea;
    }
};
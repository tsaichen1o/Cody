/**
 * @file 20241121_2257.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 2257. Count Unguarded Cells in the Grid
 * @version 0.1
 * @date 2024-11-22
 * 
 * @copyright Copyright (c) 2024
 * 
 */

class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, 0));
        
        // Mark guards and walls on the grid
        for (const auto& guard : guards) {
            grid[guard[0]][guard[1]] = 2; // Guard represented as 2
        }
        for (const auto& wall : walls) {
            grid[wall[0]][wall[1]] = 1; // Wall represented as 1
        }
        
        // Mark cells guarded by guards
        for (const auto& guard : guards) {
            int row = guard[0];
            int col = guard[1];
            
            // Move left
            for (int j = col - 1; j >= 0; --j) {
                if (grid[row][j] == 1 || grid[row][j] == 2) break; // Stop at wall or another guard
                grid[row][j] = -1; // Mark as guarded
            }
            
            // Move right
            for (int j = col + 1; j < n; ++j) {
                if (grid[row][j] == 1 || grid[row][j] == 2) break; // Stop at wall or another guard
                grid[row][j] = -1; // Mark as guarded
            }
            
            // Move up
            for (int i = row - 1; i >= 0; --i) {
                if (grid[i][col] == 1 || grid[i][col] == 2) break; // Stop at wall or another guard
                grid[i][col] = -1; // Mark as guarded
            }
            
            // Move down
            for (int i = row + 1; i < m; ++i) {
                if (grid[i][col] == 1 || grid[i][col] == 2) break; // Stop at wall or another guard
                grid[i][col] = -1; // Mark as guarded
            }
        }
        
        // Count unguarded cells
        int unguardedCellCount = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    ++unguardedCellCount; // Count cells that are not guarded, not a guard, and not a wall
                }
            }
        }

        return unguardedCellCount;
    }
};

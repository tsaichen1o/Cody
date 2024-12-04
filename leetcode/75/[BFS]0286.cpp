/**
 * @file [BFS]0286.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 286. Walls and Gates
 * @version 0.1
 * @date 2024-12-04
 * 
 * @copyright Copyright (c) 2024
 * 
 */

class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        if (rooms.empty()) return;

        int numRows = rooms.size();
        int numCols = rooms[0].size();
        queue<pair<int, int>> cellsToProcess;

        // Add all gates to the queue.
        for (int row = 0; row < numRows; row++) {
            for (int col = 0; col < numCols; col++) {
                if (rooms[row][col] == 0) {
                    cellsToProcess.push({row, col});
                }
            }
        }

        // Directions for moving up, down, left, and right.
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        // Perform BFS from all gates simultaneously.
        while (!cellsToProcess.empty()) {
            auto [currentRow, currentCol] = cellsToProcess.front();
            cellsToProcess.pop();

            for (auto [rowOffset, colOffset] : directions) {
                int neighborRow = currentRow + rowOffset;
                int neighborCol = currentCol + colOffset;

                // If the neighboring cell is within bounds and is an empty room, update its distance.
                if (neighborRow >= 0 && neighborRow < numRows && neighborCol >= 0 && neighborCol < numCols && rooms[neighborRow][neighborCol] == INT_MAX) {
                    rooms[neighborRow][neighborCol] = rooms[currentRow][currentCol] + 1;
                    cellsToProcess.push({neighborRow, neighborCol});
                }
            }
        }
    }
};

/*
Explanation:
Initialization:
Add all gates (cells with value 0) to the queue. This allows BFS to start from all gates at the same time.
BFS Traversal:
Use a queue to keep track of cells to visit. Start from each gate and propagate the distance to its neighbors.
If a neighboring cell is an empty room (rooms[r][c] == INT_MAX), update its distance to rooms[row][col] + 1 and add it to the queue.
Complexity:
Time Complexity: O(m * n) where m is the number of rows and n is the number of columns. Each cell is visited at most once.
Space Complexity: O(m * n) for the queue in the worst case if all cells are gates.
*/
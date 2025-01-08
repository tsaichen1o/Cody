/**
 * @file [BFS] 0994.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 994. Rotting Oranges
 * @version 0.1
 * @date 2024-11-29
 * 
 * @copyright Copyright (c) 2024
 * 
 */

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int timeElapse = 0;
        int rottenOrangeCount = 0, freshOrangeCount = 0, cellCount = 0;
        int rolNum = grid.size(), colNum = grid[0].size();
        queue<pair<int, int>> rottenOrangeSpots;
        // count the number of different type
        for (int i = 0; i < rolNum; i++) {
            for (int j = 0; j < colNum; j++) {
                if (grid[i][j] == 1)
                    freshOrangeCount++;
                else if (grid[i][j] == 2) {
                    rottenOrangeCount++;
                    rottenOrangeSpots.push({i, j});
                } else
                    cellCount++;
            }
        }

        if (freshOrangeCount == 0)
            return 0;
        int rottenOrangeTraversed = 0;

        while (!rottenOrangeSpots.empty()) {
            int n = rottenOrangeSpots.size();

            // cout << rolIdx << ' ' << colIdx << endl;
            bool newRotten = false;
            for (int i = 0; i < n; i++) {
                auto rottenOrangeSpot = rottenOrangeSpots.front();
                int rolIdx = rottenOrangeSpot.first;
                int colIdx = rottenOrangeSpot.second;
                // upper neighbor
                if ((rolIdx - 1) >= 0 && grid[rolIdx - 1][colIdx] == 1) {
                    grid[rolIdx - 1][colIdx] = 2;
                    rottenOrangeSpots.push({rolIdx - 1, colIdx});
                    newRotten = true;
                    freshOrangeCount--;
                }
                // below neighbor
                if ((rolIdx + 1) < rolNum && grid[rolIdx + 1][colIdx] == 1) {
                    grid[rolIdx + 1][colIdx] = 2;
                    rottenOrangeSpots.push({rolIdx + 1, colIdx});
                    newRotten = true;
                    freshOrangeCount--;
                }
                // right neighbor
                if ((colIdx + 1) < colNum && grid[rolIdx][colIdx + 1] == 1) {
                    grid[rolIdx][colIdx + 1] = 2;
                    rottenOrangeSpots.push({rolIdx, colIdx + 1});
                    newRotten = true;
                    freshOrangeCount--;
                }
                // left neighbor
                if ((colIdx - 1) >= 0 && grid[rolIdx][colIdx - 1] == 1) {
                    grid[rolIdx][colIdx - 1] = 2;
                    rottenOrangeSpots.push({rolIdx, colIdx - 1});
                    newRotten = true;
                    freshOrangeCount--;
                }
                rottenOrangeSpots.pop();
            }

            if (newRotten) {
                // freshOrangeCount--;
                timeElapse++;
            }
            rottenOrangeTraversed++;
        }

        return freshOrangeCount == 0 ? timeElapse : -1;

        // cout
        while (!rottenOrangeSpots.empty()) {
            auto rottenOrangeSpot = rottenOrangeSpots.front();
            cout << rottenOrangeSpot.first << ' ' << rottenOrangeSpot.second
                 << endl;
            rottenOrangeSpots.pop();
        }
        return timeElapse;
    }
};

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int timeElapse = 0;
        int freshOrangeCount = 0;
        int rolNum = grid.size(), colNum = grid[0].size();
        queue<pair<int, int>> rottenOrangeSpots;

        // Count the number of different types of oranges and add initial rotten oranges to the queue
        for (int i = 0; i < rolNum; i++) {
            for (int j = 0; j < colNum; j++) {
                if (grid[i][j] == 1) {
                    freshOrangeCount++;
                } else if (grid[i][j] == 2) {
                    rottenOrangeSpots.push({i, j});
                }
            }
        }

        // If there are no fresh oranges, return 0
        if (freshOrangeCount == 0) return 0;

        // Perform BFS
        while (!rottenOrangeSpots.empty()) {
            int n = rottenOrangeSpots.size();
            bool newRotten = false;

            for (int i = 0; i < n; i++) {
                auto rottenOrangeSpot = rottenOrangeSpots.front();
                int rolIdx = rottenOrangeSpot.first;
                int colIdx = rottenOrangeSpot.second;
                rottenOrangeSpots.pop();

                // Check four possible directions (up, down, left, right)
                vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
                for (auto& dir : directions) {
                    int newRolIdx = rolIdx + dir.first;
                    int newColIdx = colIdx + dir.second;

                    if (newRolIdx >= 0 && newRolIdx < rolNum && newColIdx >= 0 && newColIdx < colNum && grid[newRolIdx][newColIdx] == 1) {
                        grid[newRolIdx][newColIdx] = 2;
                        rottenOrangeSpots.push({newRolIdx, newColIdx});
                        freshOrangeCount--;
                        newRotten = true;
                    }
                }
            }

            if (newRotten) {
                timeElapse++;
            }
        }

        // If there are still fresh oranges left, return -1
        return freshOrangeCount == 0 ? timeElapse : -1;
    }
};

// Time Complexity: O(m * n) where m is the number of rows and n is the number of columns in the grid
// Space Complexity: O(m * n) for the queue in the BFS approach
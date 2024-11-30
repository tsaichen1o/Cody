/**
 * @file [PQ]2577.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 2577. Minimum Time to Visit a Cell In a Grid
 * @version 0.1
 * @date 2024-11-30
 * 
 * @copyright Copyright (c) 2024
 * 
 */

class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        // If there is no path that can be taken right from the start, return -1.
        if (grid[0][1] > 1 && grid[1][0] > 1) {
            return -1;
        }
        int rows = grid.size(), cols = grid[0].size();

        // Create a distance matrix and initialize with high values (infinite equivalent).
        int distance[rows][cols];
        memset(distance, 0x3f, sizeof distance);
        // Starting point distance is 0.
        distance[0][0] = 0;

        // Use a min-heap to store the current time and positions, organized by the shortest time.
        priority_queue<tuple<int, int, int>,
                       vector<tuple<int, int, int>>,
                       greater<tuple<int, int, int>>> pq;
      
        // Start with the position (0, 0) at time 0.
        pq.emplace(0, 0, 0);

        // Array to facilitate traversing in 4 directions: up, right, down, left.
        int directionOffsets[5] = {-1, 0, 1, 0, -1};

        // Loop until the queue is empty (it will break inside the loop on reaching the end)
        while (!pq.empty()) {
            auto [currentTime, row, col] = pq.top();
            pq.pop();

            // If the end is reached, return the time.
            if (row == rows - 1 && col == cols - 1) {
                return currentTime;
            }

            // Explore neighbors in all four directions.
            for (int k = 0; k < 4; ++k) {
                int newX = row + directionOffsets[k], newY = col + directionOffsets[k + 1];
                // If the new positions are within bounds, process them.
                if (newX >= 0 && newX < rows && newY >= 0 && newY < cols) {
                    int newTime = currentTime + 1;
                    // If current time is less than required time, adjust the newTime accordingly.
                    if (newTime < grid[newX][newY]) {
                        newTime = grid[newX][newY] + (grid[newX][newY] - newTime) % 2;
                    }
                    // If the calculated time is less than the known shortest time, update the distance and enqueue.
                    if (newTime < distance[newX][newY]) {
                        distance[newX][newY] = newTime;
                        pq.emplace(newTime, newX, newY);
                    }
                }
            }
        }
        // In the context of the original code, the loop is infinite; hence, we should never reach this point.
        // We can add a return statement here for the sake of correctness, but ideally, it should never be reached.
        return -1;
    }
};

class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        if (grid[0][1] > 1 && grid[1][0] > 1) return -1;

        int rows = grid.size(), cols = grid[0].size();
        vector<vector<int>> distance(rows, vector<int>(cols, INT_MAX));
        distance[0][0] = 0;

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        pq.push({0, {0, 0}});
        vector<int> directions = {-1, 0, 1, 0, -1};

        while (!pq.empty()) {
            auto [currentTime, pos] = pq.top();
            int row = pos.first, col = pos.second;
            pq.pop();

            if (row == rows - 1 && col == cols - 1) return currentTime;

            for (int k = 0; k < 4; ++k) {
                int newX = row + directions[k], newY = col + directions[k + 1];
                if (newX >= 0 && newX < rows && newY >= 0 && newY < cols) {
                    int newTime = currentTime + 1;
                    if (newTime < grid[newX][newY]) {
                        newTime = grid[newX][newY] + (grid[newX][newY] - newTime) % 2;
                    }
                    if (newTime < distance[newX][newY]) {
                        distance[newX][newY] = newTime;
                        pq.push({newTime, {newX, newY}});
                    }
                }
            }
        }
        return -1;
    }
};

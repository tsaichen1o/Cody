/**
 * @file 20241125_0773.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 773. Sliding Puzzle
 * @version 0.1
 * @date 2024-11-25
 * 
 * @copyright Copyright (c) 2024
 * 
 */

class Solution {
public:
    // Fixed dimensions of the puzzle: m x n (2 x 3)
    const int m = 2;
    const int n = 3;

    // Function to solve the sliding puzzle
    int slidingPuzzle(vector<vector<int>>& board) {
        // Start and goal states as strings
        string startState, tmpSequence;
        const string goalState = "123450";

        // Convert the board to starting string state and create a sequence for checking solvability
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                startState += char(board[i][j] + '0');
                if (board[i][j] != 0) tmpSequence += char(board[i][j] + '0');
            }
        }

        // Check if the board is solvable
        if (!isSolvable(tmpSequence)) return -1;

        // Use A* search algorithm
        priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> searchQueue;
        unordered_map<string, int> distances;
        distances[startState] = 0;
        searchQueue.push({heuristic(startState), startState});

        // Directions for neighbours: up, right, down, left
        vector<int> directions = {-1, 0, 1, 0, -1};

        while (!searchQueue.empty()) {
            auto currentNode = searchQueue.top();
            searchQueue.pop();
            string currentState = currentNode.second;
            int currentSteps = distances[currentState];

            // If goal state is reached, return the steps count
            if (currentState == goalState) return currentSteps;

            int zeroPosition = currentState.find('0');
            int i = zeroPosition / n, j = zeroPosition % n;

            // Explore all neighbouring states
            for (int k = 0; k < 4; ++k) {
                int newX = i + directions[k], newY = j + directions[k + 1];
                if (newX < 0 || newX >= m || newY < 0 || newY >= n) continue;
                int newPosition = newX * n + newY;
                swap(currentState[zeroPosition], currentState[newPosition]);

                // Update distance if not seen before or if a better path is found
                if (!distances.count(currentState) || distances[currentState] > currentSteps + 1) {
                    distances[currentState] = currentSteps + 1;
                    searchQueue.push({currentSteps + 1 + heuristic(currentState), currentState});
                }

                // Swap back to restore state
                swap(currentState[zeroPosition], currentState[newPosition]);
            }
        }

        // If the goal state was never reached, return -1
        return -1;
    }

    // Function to check if a given sequence is solvable
    bool isSolvable(string sequence) {
        int inversions = 0;
        int size = sequence.size();
        for (int i = 0; i < size; ++i) {
            for (int j = i + 1; j < size; ++j) {
                if (sequence[i] > sequence[j]) ++inversions;
            }
        }
        // Puzzle is solvable if the number of inversions is even
        return inversions % 2 == 0;
    }

    // Heuristic function for A* Search: calculates the manhattan distance for misplaced tiles
    int heuristic(string state) {
        int totalManhattanDistance = 0;
        for (int i = 0; i < m * n; ++i) {
            if (state[i] == '0') continue; // Skip the empty tile
            int tileNumber = state[i] - '1'; // Convert character to number and adjust index
            // Accumulate manhattan distance for each tile
            totalManhattanDistance += abs(tileNumber / n - i / n) + abs(tileNumber % n - i % n);
        }
        return totalManhattanDistance;
    }
};
/**
 * @author TC LO
 * @email b09705059@gmail.com
 * @create date 2024-09-04 23:31:09
 * @modify date 2024-09-04 23:31:09
 * @desc 874. Walking Robot Simulation
 */


class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int currentX = 0, currentY = 0, currentOrientation = 0, n = 0;
        int currentDistance = 0, maxDistance = 0;
        n = commands.size();

        for (int i = 0; i < n; i++) {
            if (commands[i] == -1) {
                // turn right 90 degrees
                currentOrientation = (currentOrientation + 1) % 4;
            } else if (commands[i] == -2) {
                // turn left 90 degrees
                currentOrientation = (currentOrientation + 3) % 4;
            } else {
                // move forward
                if (currentOrientation == 0) {
                    // north
                    for (int j = 0; j < commands[i]; j++) {
                        currentY++;
                        for (const auto& obstacle : obstacles) {
                            if (currentX == obstacle[0] &&
                                currentY == obstacle[1]) {
                                currentY--;
                                break;
                            }
                        }
                    }
                } else if (currentOrientation == 1) {
                    // east
                    for (int j = 0; j < commands[i]; j++) {
                        currentX++;
                        for (const auto& obstacle : obstacles) {
                            if (currentX == obstacle[0] &&
                                currentY == obstacle[1]) {
                                currentX--;
                                break;
                            }
                        }
                    }
                } else if (currentOrientation == 2) {
                    // south
                    for (int j = 0; j < commands[i]; j++) {
                        currentY--;
                        for (const auto& obstacle : obstacles) {
                            if (currentX == obstacle[0] &&
                                currentY == obstacle[1]) {
                                currentY++;
                                break;
                            }
                        }
                    }
                } else {
                    // west
                    for (int j = 0; j < commands[i]; j++) {
                        currentX--;
                        for (const auto& obstacle : obstacles) {
                            if (currentX == obstacle[0] &&
                                currentY == obstacle[1]) {
                                currentX++;
                                break;
                            }
                        }
                    }
                }
                currentDistance = currentX * currentX + currentY * currentY;
                maxDistance = max(maxDistance, currentDistance);
            }
            // }

            cout << currentX << ' ' << currentY << endl;
        }
        cout << n << endl;
        return maxDistance;
    }
};


// Solution

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        // Direction vectors: N, E, S, W
        vector<int> dx = {0, 1, 0, -1};
        vector<int> dy = {1, 0, -1, 0};

        // Convert obstacle coordinates to a set for O(1) lookups
        set<pair<int, int>> obstacleSet;
        for (const auto& obstacle : obstacles) {
            obstacleSet.insert({obstacle[0], obstacle[1]});
        }

        int currentX = 0, currentY = 0, currentOrientation = 0;
        int maxDistance = 0;

        for (const int& command : commands) {
            if (command == -1) {
                // turn right 90 degrees
                currentOrientation = (currentOrientation + 1) % 4;
            } else if (command == -2) {
                // turn left 90 degrees
                currentOrientation = (currentOrientation + 3) % 4;
            } else {
                // move forward
                for (int step = 0; step < command; ++step) {
                    int nextX = currentX + dx[currentOrientation];
                    int nextY = currentY + dy[currentOrientation];

                    if (obstacleSet.find({nextX, nextY}) != obstacleSet.end()) {
                        break;  // Stop if an obstacle is encountered
                    }

                    currentX = nextX;
                    currentY = nextY;
                }
                maxDistance = max(maxDistance, currentX * currentX + currentY * currentY);
            }
        }

        return maxDistance;
    }
};

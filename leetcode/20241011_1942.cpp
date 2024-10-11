/**
 * @file 20241011_1942.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 1942. The Number of the Smallest Unoccupied Chair
 * @version 0.1
 * @date 2024-10-11
 * 
 * @copyright Copyright (c) 2024
 * 
 */

class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int ansChair = 0;
        int targetArrival = times[targetFriend][0];
        sort(times.begin(), times.end());
        priority_queue<int, vector<int>, greater<int>> availableChairs;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> occupiedChairs;

        for (int i = 0; i < times.size(); ++i) {
            while (!occupiedChairs.empty() && occupiedChairs.top().first <= times[i][0]) {
                availableChairs.push(occupiedChairs.top().second);
                occupiedChairs.pop();
            }

            if (times[i][0] == targetArrival) {
                ansChair = availableChairs.empty() ? occupiedChairs.size() : availableChairs.top();
            }

            if (times[i][1] == targetArrival) {
                break;
            }

            if (!availableChairs.empty()) {
                occupiedChairs.push({times[i][1], availableChairs.top()});
                availableChairs.pop();
            } else {
                occupiedChairs.push({times[i][1], occupiedChairs.size()});
            }
        }

        return ansChair;
    }
};


// 100%

class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int targetArrival = times[targetFriend][0];

        // Sort by arrival times
        sort(times.begin(), times.end());

        // Min-heaps to track the smallest available chair and occupied chairs by leave time
        priority_queue<int, vector<int>, greater<int>> availableChairs;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> occupiedChairs;

        // Initially, all chairs (starting with chair 0) are available in order
        for (int i = 0; i < times.size(); ++i) {
            availableChairs.push(i);
        }

        // Go through each friend's arrival and leaving times
        for (const auto& time : times) {
            int arrival = time[0];
            int leaving = time[1];

            // Free up chairs for friends who have left by the current arrival time
            while (!occupiedChairs.empty() && occupiedChairs.top().first <= arrival) {
                availableChairs.push(occupiedChairs.top().second);
                occupiedChairs.pop();
            }

            // Assign the smallest available chair
            int assignedChair = availableChairs.top();
            availableChairs.pop();

            // If this is the target friend, return the chair number
            if (arrival == targetArrival) {
                return assignedChair;
            }

            // Record the leaving time for the current friend with their assigned chair
            occupiedChairs.push({leaving, assignedChair});
        }

        return -1; // This should not be reached
    }
};

// my solution

/**
 * @file 20241011_1942.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 1942. The Number of the Smallest Unoccupied Chair
 * @version 0.1
 * @date 2024-10-11
 * 
 * @copyright Copyright (c) 2024
 * 
 */

class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int ansChair = 0;
        vector<pair<int, int>> timePairs;
        for (const auto& time : times) {
            timePairs.emplace_back(time[0], time[1]);
        }
        sort(timePairs.begin(), timePairs.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.first < b.first;  // Sort by the starting time (first element of each pair)
        });

        for (const auto& timePair : timePairs) {
            cout << "(" << timePair.first << ", " << timePair.second << ")" << endl;
            
        }

        for (int i = 0; i <= targetFriend; i++) {

        }

        return ansChair;
    }
};
/**
 * @file 20241208_2054[BS][DP].cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 2054. Two Best Non-Overlapping Events
 * @version 0.1
 * @date 2024-12-08
 * 
 * @copyright Copyright (c) 2024
 * 
 */

class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        // Sort events based on their starting time
        sort(events.begin(), events.end());

        int n = events.size();
        vector<int> futureMaxValue(n + 1, 0); // Max value for events from index i to n

        // Build futureMaxValue array from the end to the start
        for (int i = n - 1; i >= 0; --i) {
            futureMaxValue[i] = max(futureMaxValue[i + 1], events[i][2]);
        }

        int maxSum = 0; // Tracks the maximum value across all possible event pairs

        // Iterate through each event
        for (int i = 0; i < n; ++i) {
            int currValue = events[i][2]; // Value of the current event

            // Binary search for the earliest event starting after the current event ends
            int left = i + 1, right = n, nextEventIndex = n;
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (events[mid][0] > events[i][1]) { // Non-overlapping event found
                    right = mid;
                    nextEventIndex = mid;
                } else {
                    left = mid + 1;
                }
            }

            // Add the maximum future value if a non-overlapping event is found
            if (nextEventIndex < n) {
                currValue += futureMaxValue[nextEventIndex];
            }

            // Update the maximum sum
            maxSum = max(maxSum, currValue);
        }

        return maxSum;
    }
};

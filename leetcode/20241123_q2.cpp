/**
 * @file 20241123_.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief Q2. Shift Distance Between Two Strings
 * @version 0.1
 * @date 2024-11-23
 * 
 * @copyright Copyright (c) 2024
 * 
 */

class Solution {
public:
    long long shiftDistance(string s, string t, vector<int>& nextCost, vector<int>& previousCost) {
        long long totalDistance = 0;  // Use long long to handle large values
        int length = s.length();

        for (int i = 0; i < length; i++) {
            if (s[i] != t[i]) {
                int startIdx = s[i] - 'a';
                int endIdx = t[i] - 'a';

                // Calculate the distance in both directions
                long long clockwiseDistance = 0;  // Use long long to handle large values
                long long counterClockwiseDistance = 0;  // Use long long to handle large values

                // Clockwise distance from s[i] to t[i]
                if (startIdx <= endIdx) {
                    for (int j = startIdx; j < endIdx; j++) {
                        clockwiseDistance += nextCost[j];
                    }
                } else {
                    for (int j = startIdx; j < 26; j++) {
                        clockwiseDistance += nextCost[j];
                    }
                    for (int j = 0; j < endIdx; j++) {
                        clockwiseDistance += nextCost[j];
                    }
                }

                // Counterclockwise distance from s[i] to t[i]
                if (startIdx >= endIdx) {
                    for (int j = startIdx; j > endIdx; j--) {
                        counterClockwiseDistance += previousCost[j];
                    }
                } else {
                    for (int j = startIdx; j >= 0; j--) {
                        counterClockwiseDistance += previousCost[j];
                    }
                    for (int j = 25; j > endIdx; j--) {
                        counterClockwiseDistance += previousCost[j];
                    }
                }

                // Choose the minimum distance
                totalDistance += min(clockwiseDistance, counterClockwiseDistance);
            }
        }

        return totalDistance;
    }
};

// original
class Solution {
public:
    long long shiftDistance(string s, string t, vector<int>& nextCost, vector<int>& previousCost) {
        long long totalDistance = 0;
        int length = s.length();
        for (int i = 0; i < length; i++) {
            if (s[i] != t[i]) {
                int nextShiftCost = 0, currentMinShiftCost = 0, previousShiftCost = 0;
                for (int i = s[i] - 'a'; i <= t[i] - 'a'; i++) {
                    nextShiftCost += nextCost[s[i] - 'a'];
                }
                for (int i = (s[i] - 'a'); i >= t[i] - 'a'; i--) {
                    previousShiftCost += previousCost[s[i] - 'a'];
                }
               currentMinShiftCost = min(nextShiftCost, previousShiftCost);
                // cout << s[i] - 'a' << ' ' << s[i] - 'a' << endl;
                totalDistance += currentMinShiftCost;
            }
        }
        return totalDistance;
    }
};

/*
Explanation:
Clockwise Distance:
If the starting character index is less than or equal to the target character index, we simply iterate forward and add the corresponding nextCost.
Otherwise, it needs to wrap around from z back to a.
Counterclockwise Distance:
If the starting character index is greater than or equal to the target character index, iterate backward using previousCost.
Otherwise, it needs to wrap around from a to z.
*/
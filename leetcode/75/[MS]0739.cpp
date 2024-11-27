/**
 * @file [MS]0739.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 739. Daily Temperatures
 * @version 0.1
 * @date 2024-11-25
 * https://leetcode.com/problems/daily-temperatures/description/
 * @copyright Copyright (c) 2024
 * 
 */

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int dayNum = temperatures.size();
        stack<int> temperaturesStk;  // Monotonic stack to store indices
        vector<int> waitingDays(dayNum, 0);

        for (int i = dayNum - 1; i >= 0; i--) {
            // Compare current temperature with the temperature stored in the stack
            while (!temperaturesStk.empty() && temperatures[i] >= temperatures[temperaturesStk.top()]) {
                temperaturesStk.pop();
            }

            if (!temperaturesStk.empty()) {
                waitingDays[i] = temperaturesStk.top() - i;  // Calculate how many days to wait
            }

            temperaturesStk.push(i);  // Push current index to the stack
        }

        return waitingDays;
    }
};

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int dayNum = temperatures.size();
        stack<int> temperaturesStk;  // Monotonic stack to store indices of temperatures
        vector<int> waitingDays(dayNum, 0);  // Result vector initialized with 0

        for (int i = 0; i < dayNum; i++) {
            // While stack is not empty and current temperature is greater than the temperature at the index on top of the stack
            while (!temperaturesStk.empty() && temperatures[i] > temperatures[temperaturesStk.top()]) {
                int prevIndex = temperaturesStk.top();
                temperaturesStk.pop();
                waitingDays[prevIndex] = i - prevIndex;  // Calculate the difference in days
            }
            temperaturesStk.push(i);  // Push the current index onto the stack
        }

        return waitingDays;
    }
};

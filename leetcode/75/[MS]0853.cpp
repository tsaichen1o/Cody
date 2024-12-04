/**
 * @file [MS]0853.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 853. Car Fleet
 * @version 0.1
 * @date 2024-12-02
 * 
 * @copyright Copyright (c) 2024
 * 
 */

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, double>> cars;

        // Calculate time to reach the target for each car
        for (int i = 0; i < n; ++i) {
            double time = static_cast<double>(target - position[i]) / speed[i];
            cars.push_back({position[i], time});
        }

        // Sort cars by position in descending order
        sort(cars.rbegin(), cars.rend());

        // Monotonic stack to keep track of car fleets
        stack<double> stack;

        // Iterate through the sorted cars
        for (const auto& car : cars) {
            double currentTime = car.second;

            // If the current car's time is greater than the top of the stack,
            // it means it forms a new fleet, so push it onto the stack
            if (stack.empty() || currentTime > stack.top()) {
                stack.push(currentTime);
            }
        }

        // The size of the stack gives the number of car fleets
        return stack.size();
    }
};

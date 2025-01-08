/**
 * @file [BFS]0000.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2024-12-03
 * https://leetcode.com/discuss/interview-question/1361977/shortest-path-question-with-a-twist
 * @copyright Copyright (c) 2024
 * 
 */

#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <iostream>

using namespace std;

struct State {
    int city;
    int fuel;
    int distance;
};

int shortestPathWithFuel(const vector<pair<int, int>>& roads, int start, int end, int capacity, const unordered_set<int>& fuelStations) {
    unordered_map<int, vector<int>> graph;
    for (auto& road : roads) {
        graph[road.first].push_back(road.second);
        graph[road.second].push_back(road.first);
    }
    
    queue<State> q;
    q.push({start, capacity, 0});
    unordered_map<int, unordered_map<int, bool>> visited;
    visited[start][capacity] = true;

    while (!q.empty()) {
        auto state = q.front();
        q.pop();
        int city = state.city;
        int fuel = state.fuel;
        int distance = state.distance;

        if (city == end) {
            return distance;
        }

        if (fuelStations.count(city)) {
            fuel = capacity;
        }

        for (int neighbor : graph[city]) {
            if (fuel > 0 && !visited[neighbor][fuel - 1]) {
                visited[neighbor][fuel - 1] = true;
                q.push({neighbor, fuel - 1, distance + 1});
            }
        }
    }

    return -1;
}

int main() {
    vector<pair<int, int>> roads = {{1, 2}, {2, 3}, {3, 4}, {4, 5}, {4, 6}, {6, 7}};
    int A = 1, B = 7, capacity = 4;
    unordered_set<int> fuelStations = {5};

    int result = shortestPathWithFuel(roads, A, B, capacity, fuelStations);
    cout << "Shortest path distance: " << result << endl;
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(n)
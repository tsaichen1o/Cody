/**
 * @file 03_FirstUnique.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief O(N * log(N))
 * @version 0.1
 * @date 2024-03-10
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<int> &A) {
    unordered_map<int, pair<int, int>> countMap; // Map to store count and position of each number

    // Count the occurrences and store the position of each number
    for (int i = 0; i < A.size(); ++i) {
        if (countMap.find(A[i]) != countMap.end()) {
            countMap[A[i]].first++; // Increment count
        } else {
            countMap[A[i]] = make_pair(1, i); // Initialize count and position
        }
    }

    // Find the first unique number with count 1 and return its position
    int minPos = A.size(); // Initialize with the maximum possible value
    for (auto& entry : countMap) {
        if (entry.second.first == 1) { // Unique number with count 1
            minPos = min(minPos, entry.second.second); // Update minimum position
        }
    }

    // If no unique number is found, return -1
    return minPos == A.size() ? -1 : A[minPos];
}

// without using hash table
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<int> &A) {
    // HashMap to store the count of each number and its first occurrence position
    unordered_map<int, pair<int, int>> occurrences;

    // Initialize the minimum position to the end of the array
    int minPos = A.size();

    // Iterate through the array to count occurrences and store positions
    for (int i = 0; i < A.size(); ++i) {
        int num = A[i];
        if (occurrences.find(num) == occurrences.end()) {
            occurrences[num] = make_pair(1, i);
        } else {
            occurrences[num].first++;
        }
    }

    // Find the first unique number with count 1 and lowest position
    int minCount = -1;
    for (auto& pair : occurrences) {
        if (pair.second.first == 1 && pair.second.second < minPos) {
            minPos = pair.second.second;
            minCount = pair.first;
        }
    }

    // Return the first unique number or -1 if none is found
    return minCount;
}

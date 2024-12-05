/**
 * @file [PQ]0767.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 767. Reorganize String
 * @version 0.1
 * @date 2024-12-05
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <queue>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string reorganizeString(string s) {
        vector<int> counts(26, 0);
        for (char c : s)
            ++counts[c - 'a'];

        // Construct a max-heap based on character frequency
        priority_queue<pair<int, char>> maxHeap;
        for (int i = 0; i < 26; ++i)
            if (counts[i])
                maxHeap.push({counts[i], 'a' + i});

        string result;
        pair<int, char> prev = {0, ' '};  // Placeholder to hold the previous character

        // Build the result string
        while (!maxHeap.empty()) {
            auto [count, ch] = maxHeap.top();
            maxHeap.pop();

            result += ch;
            if (prev.first > 0) {
                maxHeap.push(prev);
            }

            prev = {count - 1, ch};  // Decrease the count and keep for next iteration if still needed
        }

        // Check if the result is valid
        return result.size() == s.size() ? result : "";
    }
};


//
class Solution {
public:
    // Function to reorganize the string such that no two adjacent characters are the same
    string reorganizeString(string s) {
        vector<int> counts(26, 0); // Counts for each character in the alphabet
        // Calculate the counts for each character in the string
        for (char c : s) {
            ++counts[c - 'a'];
        }
        // Find the maximum occurrence of a character
        int maxCount = *max_element(counts.begin(), counts.end());
        int n = s.size();
        // If the maximum count is more than half the length of the string, reorganization is not possible
        if (maxCount > (n + 1) / 2) return "";
      
        // Pairing count of characters with their corresponding alphabet index
        vector<pair<int, int>> charCounts;
        for (int i = 0; i < 26; ++i) {
            if (counts[i]) {
                charCounts.push_back({counts[i], i});
            }
        }
        // Sort the character counts in ascending order
        sort(charCounts.begin(), charCounts.end());
        // Then reverse to have descending order
        reverse(charCounts.begin(), charCounts.end());
      
        // Prepare the result string with the same length as the input
        string result = s;
        int idx = 0; // Index to keep track of placement in result string
      
        // Loop through sorted character counts and distribute characters across the result string
        for (auto& entry : charCounts) {
            int count = entry.first, alphabetIndex = entry.second;
            while (count--) {
                // Place the character at the index, then skip one place for the next character
                result[idx] = 'a' + alphabetIndex;
                idx += 2; // Move to the next position skipping one
              
                // If we reach or pass the end of the string, start placing characters at the first odd index
                if (idx >= n) idx = 1;
            }
        }
        // Return the reorganized string
        return result;
    }
};
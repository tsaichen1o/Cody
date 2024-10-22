/**
 * @file 20241021_1593.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 1593. Split a String Into the Max Number of Unique Substrings
 * @version 0.1
 * @date 2024-10-21
 * 
 * @copyright Copyright (c) 2024
 * 
 */

class Solution {
public:
    unordered_set<string> visited;  // Set to store visited substrings
    string inputString;
    int maxCount = 1;               // Store the maximum count of unique splits

    // The main function to be called to find the maximum number of unique splits
    int maxUniqueSplit(string s) {
        inputString = s;
        dfs(0, 0); // Begin the depth-first search (DFS) from the first character
        return maxCount;
    }

    // The DFS function to explore all possible unique splits
    void dfs(int startIndex, int uniqueCount) {
        // Base case: if the index has reached or exceeded the size of the string
        if (startIndex >= inputString.size()) {
            // Update the maximum count of unique splits found so far
            maxCount = max(maxCount, uniqueCount);
            return;
        }

        // Iterate through the string, attempting to split at each index
        for (int endIndex = startIndex + 1; endIndex <= inputString.size(); ++endIndex) {
            // Generate the current substring using substr
            string currentSubstring = inputString.substr(startIndex, endIndex - startIndex);

            // Check if the substring has not been visited (i.e., is unique)
            if (!visited.count(currentSubstring)) {
                // Mark the substring as visited
                visited.insert(currentSubstring);
              
                // Recursively call dfs with the updated parameters to proceed with the next part of the string
                dfs(endIndex, uniqueCount + 1);

                // Backtrack: erase the current substring from visited set as we return from the recursion
                visited.erase(currentSubstring);
            }
        }
    }
};
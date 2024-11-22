/**
 * @file 20241122_1072.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 1072. Flip Columns For Maximum Number of Equal Rows
 * @version 0.1
 * @date 2024-11-22
 * 
 * @copyright Copyright (c) 2024
 * 
 */

class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string, int> patternCount;
        int m = matrix.size(), n = matrix[0].size();

        // Iterate through each row to determine a normalized pattern
        for (int i = 0; i < m; ++i) {
            string pattern = "";
            for (int j = 0; j < n; ++j) {
                // Normalize row based on the first element of the row
                pattern += (matrix[i][j] == matrix[i][0]) ? '0' : '1';
            }
            // Increment the count for the normalized pattern
            patternCount[pattern]++;
        }

        int maxRows = 0;
        // Find the pattern that occurs the most
        for (auto& entry : patternCount) {
            maxRows = max(maxRows, entry.second);
        }

        return maxRows;
    }
};

/*
Improved Approach:
The approach is to convert each row into a "base form" and count how many rows share the same form. Specifically:

Normalize Each Row: We represent each row such that if the first element of the row is 0, we keep the row as-is, and if it's 1, we flip all values. This way, each row can be represented consistently.
Count Frequency: We use a hashmap to count the frequency of each normalized row form. The answer will be the maximum count found in the hashmap.
*/

/*
Normalization:

For each row, we create a normalized pattern. The normalized pattern is determined by considering the first element in the row:
If the first element is 0, we map each element to 0 or 1 to reflect whether it is equal to the first element.
If the first element is 1, we flip every value to make it consistent.
Pattern Count:

We store the frequency of each pattern using an unordered map.
The result is simply the maximum frequency found among all patterns.
*/
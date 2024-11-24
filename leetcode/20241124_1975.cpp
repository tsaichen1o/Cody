/**
 * @file 20241124_1975.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 1975. Maximum Matrix Sum
 * @version 0.1
 * @date 2024-11-24
 * 
 * @copyright Copyright (c) 2024
 * 
 */

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        long long totalSum = 0;
        int minAbsValue = INT_MAX;
        int negativeCount = 0;

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                int value = matrix[i][j];
                totalSum += abs(value);
                if (value < 0) {
                    negativeCount++;
                }
                minAbsValue = min(minAbsValue, abs(value));
            }
        }

        // If there are an odd number of negative values, we need to subtract twice the smallest absolute value
        if (negativeCount % 2 != 0) {
            totalSum -= 2 * minAbsValue;
        }

        return totalSum;
    }
};

/*
Explanation:
Sum of Absolute Values: We iterate over the entire matrix to calculate the total sum of absolute values (totalSum), count the negative values (negativeCount), and track the smallest absolute value (minAbsValue).

Adjusting for Odd Negatives: If the number of negative values is odd, it means that after all possible sign flips, there will be one element left negative. To maximize the sum, we subtract twice the smallest absolute value.

This approach ensures that you get the maximum possible sum after applying the given operations. The time complexity is O(n^2), which is efficient given the problem constraints (n <= 250).
*/
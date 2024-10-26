/**
 * @file 20241026_0097.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 97. Interleaving String
 * @version 0.1
 * @date 2024-10-26
 * https://algo.monster/liteproblems/97
 * @copyright Copyright (c) 2024
 * 
 */

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.length();
        int n = s2.length();

        // If total length doesn't match, s1 and s2 can't interleave to form s3
        if ((m + n) != s3.length()) return false;

        // Create a DP table initialized to false
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;  // Empty s1 and s2 can form empty s3

        // Fill first row (using only s1)
        for (int i = 1; i <= m; i++) {
            if (s1[i - 1] == s3[i - 1]) {
                dp[i][0] = true;
            } else {
                break;  // If there's a mismatch, break out of the loop
            }
        }

        // Fill first column (using only s2)
        for (int j = 1; j <= n; j++) {
            if (s2[j - 1] == s3[j - 1]) {
                dp[0][j] = true;
            } else {
                break;  // If there's a mismatch, break out of the loop
            }
        }

        // Fill the rest of the DP table
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                // If current char of s1 matches s3, check if s1 up to i-1 and s2 up to j can form s3
                if (s1[i - 1] == s3[i + j - 1]) {
                    dp[i][j] = dp[i][j] || dp[i - 1][j];
                }
                // If current char of s2 matches s3, check if s1 up to i and s2 up to j-1 can form s3
                if (s2[j - 1] == s3[i + j - 1]) {
                    dp[i][j] = dp[i][j] || dp[i][j - 1];
                }
            }
        }

        // Return whether the whole s1 and s2 can interleave to form s3
        return dp[m][n];
    }
};
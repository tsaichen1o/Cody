/**
 * @file 20240925_2707.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 2707. Extra Characters in a String
 * @version 0.1
 * @date 2024-09-25
 * 
 * @copyright Copyright (c) 2024
 * 
 */

/*
You are given a 0-indexed string s and a dictionary of words dictionary. You have to break s into one or more non-overlapping substrings such that each substring is present in dictionary. There may be some extra characters in s which are not present in any of the substrings.

Return the minimum number of extra characters left over if you break up s optimally.



Example 1:

Input: s = "leetscode", dictionary = ["leet","code","leetcode"]
Output: 1
Explanation: We can break s in two substrings: "leet" from index 0 to 3 and "code" from index 5 to 8. There is only 1 unused character (at index 4), so we return 1.

Example 2:

Input: s = "sayhelloworld", dictionary = ["hello","world"]
Output: 3
Explanation: We can break s in two substrings: "hello" from index 3 to 7 and "world" from index 8 to 12. The characters at indices 0, 1, 2 are not used in any substring and thus are considered as extra characters. Hence, we return 3.
*/

class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.size();
        int m = dictionary.size();
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int len = dictionary[j].size();
                if (i+len <= n && s.substr(i, len) == dictionary[j]) {
                    dp[i+len] = min(dp[i+len], dp[i]);
                }
            }
            dp[i+1] = min(dp[i+1], dp[i]+1);
        }
        return dp[n];
    }
};
/**
 * @file 20241012_3314.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 3314. Find Maximum Removals From Source String
 * @version 0.1
 * @date 2024-10-12
 * 
 * @copyright Copyright (c) 2024
 * 
 */

class Solution {
public:
    int maxRemovals(string source, string pattern, vector<int>& targetIndices) {
        int ans = 0;
        int n = source.size();
        int left = 0, right = targetIndices.size();
        vector<bool> removed(n, false);

        auto isSubsequence = [&](int k) {
            int i = 0, j = 0;
            for (int idx = 0; idx < n && j < pattern.size(); ++idx) {
                if (i < k && targetIndices[i] == idx) {
                    ++i;
                    continue;
                }
                if (source[idx] == pattern[j]) {
                    ++j;
                }
            }
            return j == pattern.size();
        };

        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (isSubsequence(mid)) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return ans;
    }
};
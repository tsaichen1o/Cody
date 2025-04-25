/**
 * @file 2799_count_complete_subarrays.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief
 * @version 0.1
 * @date 2025-04-24
 *
 * @copyright Copyright (c) 2025
 *
 */

// 題目: Count Complete Subarrays
// 類型: Brute Force, HashSet, Sliding Window
// 難度: Medium
// 解法:
// - complete 子陣列定義：其 distinct 數量等於原始陣列的 distinct 數量。
// - 先用 set 算出整個陣列的 distinct 數 totalDistinct。
// - 再用雙層迴圈列舉所有子陣列，並用 unordered_set 判斷 distinct 數。
// - 若等於 totalDistinct，則是 complete 子陣列，累加計數。

class Solution
{
public:
    int countCompleteSubarrays(vector<int> &nums)
    {
        int n = nums.size();
        unordered_set<int> all(nums.begin(), nums.end());
        int totalDistinct = all.size();

        int result = 0;

        for (int i = 0; i < n; ++i)
        {
            unordered_set<int> seen;
            for (int j = i; j < n; ++j)
            {
                seen.insert(nums[j]);
                if (seen.size() == totalDistinct)
                {
                    result++;
                }
            }
        }

        return result;
    }
};

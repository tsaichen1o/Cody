/**
 * @file 2145_number_of_valid_hidden_sequences.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief
 * @version 0.1
 * @date 2025-04-24
 *
 * @copyright Copyright (c) 2025
 *
 */

// 題目: Number of Valid Hidden Sequences
// 類型: Prefix Sum, Math
// 難度: Easy
// 解法:
// - 設 hidden[0] 為 x，其他元素透過 prefix sum 累加得到。
// - 整個序列中的值為 x + prefixSum[i]
// - 所以要滿足所有元素在 [lower, upper] 區間，
//   就是要讓 x ∈ [lower - min_prefix, upper - max_prefix]
// - 合法範圍長度 = (upper - max_prefix) - (lower - min_prefix) + 1

class Solution
{
public:
    int numberOfArrays(vector<int> &differences, int lower, int upper)
    {
        long long prefix = 0;
        long long min_prefix = 0, max_prefix = 0;

        for (int diff : differences)
        {
            prefix += diff;
            min_prefix = min(min_prefix, prefix);
            max_prefix = max(max_prefix, prefix);
        }

        long long min_start = lower - min_prefix;
        long long max_start = upper - max_prefix;

        long long possible_starts = max_start - min_start + 1;

        return possible_starts >= 0 ? possible_starts : 0;
    }
};

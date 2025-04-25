/**
 * @file 2338_ideal_arrays.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2025-04-24
 * 
 * @copyright Copyright (c) 2025
 * 
 */

// 題目: Ideal Arrays
// 類型: Dynamic Programming, Combinatorics, Math
// 難度: Hard
// 解法:
// - 每個位置的值必須是前一個的倍數，所以本質是構造一個「乘法鏈」。
// - dp[i][k]: 以 i 為結尾、長度為 k 的乘法鏈數量。
// - 對每個數字 i，統計所有倍數 j = 2i, 3i... 更新 dp[j][k]。
// - 對於長度為 k 的乘法鏈，用組合數 C(n-1, k-1) 決定可以擴展為長度 n 的方法數。
// - 結果為所有 dp[val][len] * C(n-1, len-1) 的加總。
// - 使用 combinatorics 表預先算好 C(n, k) 表。

class Solution {
    public:
        const int MOD = 1e9 + 7;
        vector<vector<int>> dp;
        vector<vector<int>> comb;
    
        int idealArrays(int n, int maxValue) {
            const int MAXK = 14; // 最長乘法鏈長度不會超過 log2(maxValue)
            
            // 預處理組合數 comb[n][k] = C(n, k)
            comb = vector<vector<int>>(n + 1, vector<int>(MAXK + 1));
            for (int i = 0; i <= n; ++i) {
                comb[i][0] = 1;
                for (int j = 1; j <= MAXK && j <= i; ++j) {
                    comb[i][j] = (comb[i-1][j] + comb[i-1][j-1]) % MOD;
                }
            }
    
            // dp[val][len]: 長度為 len，以 val 結尾的乘法鏈有幾種
            dp = vector<vector<int>>(maxValue + 1, vector<int>(MAXK + 1, 0));
            for (int i = 1; i <= maxValue; ++i) {
                dp[i][1] = 1;
            }
    
            for (int len = 2; len <= MAXK; ++len) {
                for (int i = 1; i <= maxValue; ++i) {
                    for (int j = 2 * i; j <= maxValue; j += i) {
                        dp[j][len] = (dp[j][len] + dp[i][len - 1]) % MOD;
                    }
                }
            }
    
            long long result = 0;
            for (int val = 1; val <= maxValue; ++val) {
                for (int len = 1; len <= MAXK; ++len) {
                    result = (result + (long long)dp[val][len] * comb[n - 1][len - 1]) % MOD;
                }
            }
    
            return result;
        }
    };
    
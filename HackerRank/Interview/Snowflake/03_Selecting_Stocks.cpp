/**
 * @file 03_Selecting_Stocks.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief Selecting Stocks
 * @version 0.1
 * @date 2024-11-20
 * 
 * @copyright Copyright (c) 2024
 * 
 */

int selectStock(int saving, vector<int>& currentValue, vector<int>& futureValue) {
    int n = currentValue.size();
    vector<int> dp(saving + 1, 0);

    for (int i = 0; i < n; ++i) {
        int cost = currentValue[i];
        int profit = futureValue[i] - currentValue[i];
        for (int j = saving; j >= cost; --j) {
            dp[j] = max(dp[j], dp[j - cost] + profit);
        }
    }
    return dp[saving];
}

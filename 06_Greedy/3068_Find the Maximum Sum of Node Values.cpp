// 題目: Maximum Value Sum of a Tree With Operations
// 類型: Greedy, XOR, Parity
// 難度: Medium
// 解法:
// - 這題其實和樹結構無關，只與可選點個數偶奇有關
// - 每條邊能讓兩個點 xor k，任意偶數個點可以異或
// - 對每點計算異或 k 的增益，貪心取偶數個最大增益

class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long baseSum = 0;
        vector<long long> gains;

        for (int num : nums) {
            baseSum += num;
            gains.push_back((num ^ k) - num);
        }
        sort(gains.rbegin(), gains.rend());
        long long maxSum = baseSum;
        long long sum = baseSum;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            sum += gains[i];
            if ((i + 1) % 2 == 0) {
                maxSum = max(maxSum, sum);
            }
        }
        return maxSum;
    }
};
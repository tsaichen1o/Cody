/**
 * @file 20241005_0440.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 440. K-th Smallest in Lexicographical Order
 * @version 0.1
 * @date 2024-10-05
 * 
 * @copyright Copyright (c) 2024
 * 
 */

class Solution {
public:
    int findKthNumber(int n, int k) {
        int current = 1;
        k--;  // 因为我们从1开始，所以k需要减1

        while (k > 0) {
            long long step = 0, first = current, last = current + 1;
            
            // 计算当前前缀下的节点数
            while (first <= n) {
                step += min((long long)n + 1, last) - first;
                first *= 10;
                last *= 10;
            }

            if (step <= k) {
                // 如果节点数小于等于k，移动到下一个前缀
                k -= step;
                current++;
            } else {
                // 否则，进入当前前缀的子树
                k--;
                current *= 10;
            }
        }

        return current;
    }
};
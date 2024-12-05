/**
 * @file 0000.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2024-12-05
 * 
 * @copyright Copyright (c) 2024
 * 
 */

class Solution {
public:
    int solution(int S) {
        int count = 0;
        
        // Loop over all possible values for the four digits (0-9)
        for (int d1 = 0; d1 <= 9; ++d1) {
            for (int d2 = 0; d2 <= 9; ++d2) {
                for (int d3 = 0; d3 <= 9; ++d3) {
                    int d4 = S - d1 - d2 - d3;
                    if (d4 >= 0 && d4 <= 9) {
                        count++;
                    }
                }
            }
        }
        
        return count;
    }
};

// 
#include <vector>
#include <unordered_map>

class Solution {
public:
    int solution(int S) {
        std::unordered_map<int, int> memo; // Memoize the results
        return countWays(S, 4, memo);
    }

private:
    int countWays(int sum, int digits, std::unordered_map<int, int>& memo) {
        if (digits == 0) return sum == 0 ? 1 : 0; // Base case: found a valid combination
        if (sum < 0) return 0; // No valid solution for negative sums

        int key = (sum << 4) | digits; // Create a unique key for memoization
        if (memo.count(key)) return memo[key]; // Return already computed result

        int count = 0;
        for (int i = 0; i <= 15; ++i) { // Loop over all possible hexadecimal digits (0-15)
            count += countWays(sum - i, digits - 1, memo);
        }

        memo[key] = count;
        return count;
    }
};

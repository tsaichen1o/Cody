/**
 * @file [DP]1137.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 1137. N-th Tribonacci Number
 * @version 0.1
 * @date 2024-11-27
 * 
 * @copyright Copyright (c) 2024
 * 
 */

class Solution {
public:
    int tribonacci(int n) {
        vector<int> memTable(n + 1, -1);  // Initialize memo table with -1
        return fib(n, memTable);
    }

private:
    int fib(int n, vector<int>& memTable) {
        if (n == 0) {
            return 0;
        } else if (n == 1 || n == 2) {
            return 1;
        }

        // If the value is already computed, return it
        if (memTable[n] != -1) {
            return memTable[n];
        }

        // Compute the value and store it in the memo table
        memTable[n] = fib(n - 1, memTable) + fib(n - 2, memTable) + fib(n - 3, memTable);
        return memTable[n];
    }
};

/// TLE
class Solution {
public:
    int tribonacci(int n) {
        return fib(n);
    }
    
private:
    int fib(int n) {
        if (n == 0) {
            return 0;
        } else if (n == 1 || n == 2) {
            return 1;
        }
        return fib(n - 1) + fib(n - 2) + fib(n - 3);
    }
};

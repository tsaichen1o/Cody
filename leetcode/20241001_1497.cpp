/**
 * @file 20241001_1497.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 1497. Check If Array Pairs Are Divisible by k
 * @version 0.1
 * @date 2024-10-03
 * 
 * @copyright Copyright (c) 2024
 * 
 */

class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        bool answer = true;
        // int pairNum = k / 2;
        // unordered_map<int> numMap;
        unordered_map<int, int> remainderCount;
        for (int i = 0; i < arr.size(); i++) {
            int remainder = ((arr[i] % k) + k) % k;
            remainderCount[remainder]++;
        }

        for (int i = 0; i < k; i++) {
            cout << i << ' ' << remainderCount[i] << endl;
        }

        for (int i = 1; i < k; i++) {
            if (remainderCount[i] == remainderCount[k - i]){
                if (i == k - i && remainderCount[i] != 0 && remainderCount[i] % 2 != 0) {
                    answer = false;
                    break;
                }
                answer = true;
            } else {
                answer = false;
                break;
            }
        }

        return answer;
    }
};


// improve code

class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int, int> remainderCount;

        // Count remainders when divided by k
        for (int num : arr) {
            int remainder = ((num % k) + k) % k; // Ensure positive remainder
            remainderCount[remainder]++;
        }

        // Check for remainder 0, must be even count
        if (remainderCount[0] % 2 != 0) return false;

        // Check remainder pairs from 1 to k/2
        for (int i = 1; i <= k / 2; i++) {
            if (i == k - i) {
                // For the case where remainder is exactly k/2, count must be even
                if (remainderCount[i] % 2 != 0) return false;
            } else {
                // For other remainders, count[i] must match count[k - i]
                if (remainderCount[i] != remainderCount[k - i]) return false;
            }
        }

        return true;
    }
};

// 更优化的解决方案
class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> remainderCount(k, 0);
        
        // 统计余数
        for (int num : arr) {
            int remainder = ((num % k) + k) % k;
            remainderCount[remainder]++;
        }
        
        // 检查余数对
        if (remainderCount[0] % 2 != 0) return false;
        
        for (int i = 1; i <= k / 2; i++) {
            if (remainderCount[i] != remainderCount[k - i]) {
                return false;
            }
        }
        
        return true;
    }
};



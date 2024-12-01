/**
 * @file 20241201_1346.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 1346. Check If N and Its Double Exist
 * @version 0.1
 * @date 2024-12-01
 * 
 * @copyright Copyright (c) 2024
 * 
 */

// 100% faster solution
class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int, int> arrMap;

        for (int num : arr) {
            arrMap[num]++;
        }
        // arrSet.insert(arr.begin(), arr.end());
        for (int num : arr) {
            if ((arrMap.count(num * 2) || (arrMap.count(num / 2) && num % 2 == 0))) {
                if (num == 0) {
                    if (arrMap[num] == 1) return false;
                }
                return true;
            }
        }
        return false;
    }
};


// slower solution
class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> seen;

        for (int num : arr) {
            // Check if the current number is double or half of an existing value
            if (seen.count(num * 2) || (num % 2 == 0 && seen.count(num / 2))) {
                return true;
            }
            // Add the current number to the set
            seen.insert(num);
        }
        
        return false;
    }
};

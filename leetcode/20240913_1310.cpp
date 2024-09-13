/**
 * @file 20240913_1310.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 1310. XOR Queries of a Subarray
 * @version 0.1
 * @date 2024-09-13
 * 
 * @copyright Copyright (c) 2024
 * 
 */

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> answer;
    }
};

// 
class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        // Step 1: Create the prefix XOR array
        int n = arr.size();
        vector<int> prefixXOR(n + 1, 0);  // prefixXOR[i] stores XOR of arr[0] to arr[i-1]
        
        // Step 2: Compute cumulative XOR values
        for (int i = 1; i <= n; i++) {
            prefixXOR[i] = prefixXOR[i - 1] ^ arr[i - 1];
        }
        
        // Step 3: Answer each query in constant time
        vector<int> answer;
        for (const auto& query : queries) {
            int left = query[0], right = query[1];
            // XOR from arr[left] to arr[right] is calculated as:
            answer.push_back(prefixXOR[right + 1] ^ prefixXOR[left]);
        }
        
        return answer;
    }
};

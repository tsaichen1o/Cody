/**
 * @file 20241006_3309.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief Q1. Maximum Possible Number by Binary Concatenation
 * @version 0.1
 * @date 2024-10-06
 * 
 * @copyright Copyright (c) 2024
 * 
 */

class Solution {
public:
    int maxGoodNumber(vector<int>& nums) {
    int maxNum = 0;
    vector<string> binStrs;
    
    // 将每个数字转换为二进制字符串
    for (int num : nums) {
        string binStr = "";
        while (num > 0) {
            binStr = to_string(num % 2) + binStr;
            num /= 2;
        }
        binStrs.push_back(binStr);
    }
    
    // 对二进制字符串进行排序，以确保最大可能的数字
    sort(binStrs.begin(), binStrs.end(), [](const string& a, const string& b) {
        return a + b > b + a;
    });
    
    // 连接排序后的二进制字符串
    string result = "";
    for (const string& binStr : binStrs) {
        result += binStr;
    }
    
    // 将结果转换回十进制
    for (char c : result) {
        maxNum = maxNum * 2 + (c - '0');
    }
    
    return maxNum;
    }
};
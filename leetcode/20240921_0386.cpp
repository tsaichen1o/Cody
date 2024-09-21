/**
 * @file 20240921_0386.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 386. Lexicographical Numbers
 * @version 0.1
 * @date 2024-09-21
 * 
 * @copyright Copyright (c) 2024
 * 
 */

/*
Given an integer n, return all the numbers in the range [1, n] sorted in lexicographical order.

You must write an algorithm that runs in O(n) time and uses O(1) extra space. 

Example 1:

Input: n = 13
Output: [1,10,11,12,13,2,3,4,5,6,7,8,9]
Example 2:

Input: n = 2
Output: [1,2]
*/
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res;

        for (int i = 0; i < n; i++) {
            res.push_back(i + 1);
        }
        

        return res;
};
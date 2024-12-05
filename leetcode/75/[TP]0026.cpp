/**
 * @file [TP]0026.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 26. Remove Duplicates from Sorted Array
 * @version 0.1
 * @date 2024-12-05
 * 
 * @copyright Copyright (c) 2024
 * 
 */

class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        int slow = 0;
        for (int fast = 0; fast < arr.size(); fast++) {
            if (arr.at(fast) != arr.at(slow)) {
                slow++;
                arr.at(slow) = arr.at(fast);
            }
        }
        return slow + 1;
    }
};
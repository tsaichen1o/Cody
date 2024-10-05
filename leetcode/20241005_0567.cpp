/**
 * @file 20241005_0567.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 567. Permutation in String
 * @version 0.1
 * @date 2024-10-05
 * 
 * @copyright Copyright (c) 2024
 * 
 */

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int len1 = s1.length(), len2 = s2.length();
        if (len1 > len2) return false;

        vector<int> count1(26), count2(26);
        for (int i = 0; i < len1; i++) {
            count1[s1[i] - 'a']++;
            count2[s2[i] - 'a']++;
        }
        if (count1 == count2) return true;

        for (int i = len1; i < len2; i++) {
            count2[s2[i] - 'a']++;
            count2[s2[i - len1] - 'a']--;
            if (count1 == count2) return true;
        }
        return false;
    }
};
/**
 * @file [TP]0125.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 125. Valid Palindrome
 * @version 0.1
 * @date 2024-12-05
 * 
 * @copyright Copyright (c) 2024
 * 
 */

class Solution {
public:
    bool isPalindrome(string s) {
        std::vector<char> arr;
        for (char c : s) {
            if (std::isalnum(c))
                arr.emplace_back(std::tolower(c));
        }

        int l = 0;
        int r = arr.size() - 1;
        while (l < r) {
            if (std::tolower(arr[l]) != std::tolower(arr[r]))
                return false;
            l++;
            r--;
        }
        return true;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0;
        int r = s.size() - 1;
        while (l < r) {
            // Note 1, 2
            while (l < r && !std::isalnum(s[l])) {
                l++;
            }
            while (l < r && !std::isalnum(s[r])) {
                r--;
            }
            // compare characters ignoring case
            if (std::tolower(s[l]) != std::tolower(s[r]))
                return false;
            l++;
            r--;
        }
        return true;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(1)
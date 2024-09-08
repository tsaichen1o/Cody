/**
 * @file 20240903_1945.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 1945. Sum of Digits of String After Convert
 * @version 0.1
 * @date 2024-09-08
 * 
 * @copyright Copyright (c) 2024
 * 
 */

// First, convert s into an integer by replacing each letter with its position in the alphabet (i.e., replace 'a' with 1, 'b' with 2, ..., 'z' with 26). Then, transform the integer by replacing it with the sum of its digits. Repeat the transform operation k times in total.

class Solution {
public:
    int getLucky(string s, int k) {
        string str = "";
        for (char c : s) {
            str += to_string(c - 'a' + 1);
        }
        int res = 0;
        for (char c : str) {
            res += c - '0';
        }
        for (int i = 1; i < k; i++) {
            int tmp = 0;
            while (res) {
                tmp += res % 10;
                res /= 10;
            }
            res = tmp;
        }
        return res;
    }
};

// 100%
class Solution {
public:
    int getLucky(string s, int k) {
        int res = 0;

        // Step 1: Convert each character to corresponding number and sum the digits directly
        for (char c : s) {
            int num = c - 'a' + 1;  // Convert char to its corresponding value (1 to 26)
            res += num / 10 + num % 10;  // Add digits of the number (handle two-digit values)
        }

        // Step 2: Perform the sum of digits transformation for `k-1` times
        for (int i = 1; i < k; i++) {
            int tmp = 0;
            while (res > 0) {
                tmp += res % 10;
                res /= 10;
            }
            res = tmp;
        }

        return res;
    }
};

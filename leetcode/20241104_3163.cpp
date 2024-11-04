/**
 * @file 20241104_3163.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 3163. String Compression III
 * @version 0.1
 * @date 2024-11-04
 * 
 * @copyright Copyright (c) 2024
 * 
 */

class Solution {
public:
    string compressedString(string word) {
        string result;
        int count = 1; // Tracks consecutive characters

        for (int i = 1; i <= word.size(); i++) {
            if (i < word.size() && word[i] == word[i - 1]) {
                count++;
            } else {
                // Append count and character in chunks of 9 if needed
                while (count > 9) {
                    result += "9" + string(1, word[i - 1]);
                    count -= 9;
                }
                result += to_string(count) + word[i - 1];
                count = 1;
            }
        }

        return result;
    }
};

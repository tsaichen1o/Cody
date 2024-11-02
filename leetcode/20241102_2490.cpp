/**
 * @file 20241102_2490.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 2490. Circular Sentence
 * @version 0.1
 * @date 2024-11-02
 * 
 * @copyright Copyright (c) 2024
 * 
 */

class Solution {
public:
    bool isCircularSentence(string sentence) {
        int n = sentence.size();
        
        // Check if the sentence starts and ends with the same character
        if (sentence[0] != sentence[n - 1]) return false;

        for (int i = 1; i < n - 1; ++i) {
            if (sentence[i] == ' ') {
                // Check if the last character of the current word matches the first of the next
                if (sentence[i - 1] != sentence[i + 1]) return false;
            }
        }
        
        return true;
    }
};



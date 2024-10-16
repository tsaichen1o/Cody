/**
 * @file 20241016_1405.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 1405. Longest Happy String
 * @version 0.1
 * @date 2024-10-16
 * 
 * @copyright Copyright (c) 2024
 * 
 */

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        // Max-heap with counts and characters (negative count to simulate max-heap)
        priority_queue<pair<int, char>> maxHeap;
        
        // Push each character count if it is greater than zero
        if (a > 0) maxHeap.push({a, 'a'});
        if (b > 0) maxHeap.push({b, 'b'});
        if (c > 0) maxHeap.push({c, 'c'});
        
        string result;
        
        // While there are characters left to process
        while (!maxHeap.empty()) {
            auto [count1, char1] = maxHeap.top(); maxHeap.pop();
            
            // Check if adding char1 will break the "happy" rule (three in a row)
            if (result.size() >= 2 && result.back() == char1 && result[result.size() - 2] == char1) {
                // If char1 is not allowed, check if there is an alternative character
                if (maxHeap.empty()) break; // No other option, we are done
                
                auto [count2, char2] = maxHeap.top(); maxHeap.pop();
                
                // Add one occurrence of char2 to the result
                result += char2;
                count2--;
                
                // Push the updated counts back to the heap
                if (count2 > 0) maxHeap.push({count2, char2});
                maxHeap.push({count1, char1}); // Put char1 back for future use
            } else {
                // Safe to add char1
                result += char1;
                count1--;
                
                // If there are more occurrences of char1, push it back to the heap
                if (count1 > 0) maxHeap.push({count1, char1});
            }
        }
        
        return result;
    }
};
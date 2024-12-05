/**
 * @file [SW]2260.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 2260. Minimum Consecutive Cards to Pick Up
 * @version 0.1
 * @date 2024-12-05
 * 
 * @copyright Copyright (c) 2024
 * 
 */

class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        std::unordered_map<int, int>
            cardFrequency;   // Stores the frequency of cards in the current
                             // window
        int leftPointer = 0; // Left pointer of the sliding window
        int minimumLength =
            cards.size() +
            1; // Start with an unattainably large value for the shortest length

        // Iterate through the cards with a sliding window approach
        for (int rightPointer = 0; rightPointer < cards.size();
             ++rightPointer) {
            cardFrequency[cards[rightPointer]]++;

            // Adjust the window if we have a duplicate
            while (cardFrequency[cards[rightPointer]] == 2) {
                minimumLength =
                    std::min(minimumLength, rightPointer - leftPointer + 1);
                cardFrequency[cards[leftPointer]]--;
                leftPointer++;
            }
        }

        return (minimumLength != cards.size() + 1)
                   ? minimumLength
                   : -1; // Return -1 if no valid sequence was found
    }
};

// Time Complexity: O(n)
// Space Complexity: O(n)
// Essentially, this question is asking for the shortest subarray that contains a duplicate.
/**
 * @file 20241123_q1.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief Q1. Stone Removal Game
 * @version 0.1
 * @date 2024-11-23
 * 
 * @copyright Copyright (c) 2024
 * 
 */

class Solution {
public:
    bool canAliceWin(int n) {
        bool isAliceWin = true;
        int counter = 10;
        if (n < 10) return false;
        while (counter) {
            n -= counter;
            counter--;
            if (n < counter) {
                isAliceWin = !isAliceWin;
            }
        }
        return isAliceWin;
    }
};

class Solution {
public:
    bool canAliceWin(int n) {
        int counter = 10; // Alice starts by removing 10 stones

        while (n >= 0) {
            n -= counter;
            if (n < 0) return false; // If it's Alice's turn and she can't make a move, she loses
            counter--; // Move to the next round
            
            n -= counter;
            if (n < 0) return true; // If it's Bob's turn and he can't make a move, Alice wins
            counter--; // Move to the next round
        }
        return false; // Default: Alice loses if no move can be made
    }
};



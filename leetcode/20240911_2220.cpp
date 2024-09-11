/**
 * @file 20240911_2220.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 2220. Minimum Bit Flips to Convert Number
 * @version 0.1
 * @date 2024-09-11
 *
 * @copyright Copyright (c) 2024
 *
 */

class Solution {
public:
    int minBitFlips(int start, int goal) {
        /*
            Input: start = 10, goal = 7
            Output: 3
            Explanation: The binary representation of 10 and 7 are 1010 and 0111
           respectively. We can convert 10 to 7 in 3 steps:
            - Flip the first bit from the right: 1010 -> 1011.
            - Flip the third bit from the right: 1011 -> 1111.
            - Flip the fourth bit from the right: 1111 -> 0111.
            It can be shown we cannot convert 10 to 7 in less than 3 steps.
           Hence, we return 3.
        */
        int res = 0;
        for (int i = 0; i < 32; i++) {
            if ((start & (1 << i)) != (goal & (1 << i))) {
                if (start & (1 << i)) {
                    res++;
                } else {
                    if (goal & (1 << i)) {
                        res++;
                    }
                }
            }
        }
        return res;
    }
};

// 
class Solution {
public:
    int minBitFlips(int start, int goal) {
        // XOR between start and goal gives the bits that are different
        int xorResult = start ^ goal;
        
        // Count the number of 1s in xorResult, which tells us how many flips are needed
        int res = 0;
        while (xorResult > 0) {
            res += xorResult & 1; // Increment res if the last bit is 1
            xorResult >>= 1;       // Right shift xorResult to check the next bit
        }
        
        return res;
    }
};

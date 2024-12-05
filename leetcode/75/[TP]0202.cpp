/**
 * @file [TP]0202.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 202. Happy Number
 * @version 0.1
 * @date 2024-12-05
 * 
 * @copyright Copyright (c) 2024
 * 
 */

class Solution {
public:
    int step(int n) {
        int res = 0;
        while (n > 0) {
            int digit = n % 10;
            res += digit * digit;
            n = n / 10;
        }
        return res;
    }

    bool isHappy(int n) {
        int tortoise = step(n);
        int hare = step(step(n));
        while (tortoise != hare && hare != 1) {
            tortoise = step(tortoise);
            hare = step(step(hare));
        }
        return hare == 1;
    }
};

// Time Complexity: O(log n), where n is the input number.
// Space Complexity: O(1).
// It uses the "Floyd's Cycle Detection" (tortoise and hare) algorithm to determine if n is a happy number.

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> seen;  // To track numbers we've seen before
        
        while (n != 1 && !seen.count(n)) {
            seen.insert(n);
            n = getNext(n);  // Replace n with the sum of the squares of its digits
        }
        
        return n == 1;
    }

private:
    int getNext(int n) {
        int sum = 0;
        while (n > 0) {
            int digit = n % 10;  // Get last digit
            sum += digit * digit; // Add square of digit
            n /= 10;  // Remove last digit
        }
        return sum;
    }
};

// Time Complexity: O(log n), where n is the input number.
// Space Complexity: O(log n), where n is the input number.
/*
Tracking Numbers with a Set:

We use an unordered_set<int> seen to track the numbers we've already seen.
If we encounter the same number again, it indicates that we are in a cycle and will never reach 1.
Helper Function:

getNext(int n) calculates the next number by summing the squares of its digits.
Loop until Result:

We repeat the process until n == 1 or we detect a cycle (by seeing the same value twice).
Space Complexity: O(log n), due to the set used to track seen numbers.
*/
class Solution {
public:
    int maximumSwap(int num) {
        // Convert num to a string for easy manipulation of digits
        string numStr = to_string(num);
        int n = numStr.size();
        
        // Create an array to store the last occurrence index of each digit
        int last[10] = {0};
        for (int i = 0; i < n; ++i) {
            last[numStr[i] - '0'] = i;
        }
        
        // Traverse through each digit to find the first position to swap
        for (int i = 0; i < n; ++i) {
            // Check for a larger digit to swap with, starting from 9 down to the current digit+1
            for (int d = 9; d > numStr[i] - '0'; --d) {
                if (last[d] > i) {
                    // If a larger digit is found later in the string, swap them
                    swap(numStr[i], numStr[last[d]]);
                    // Return the result as integer after one swap
                    return stoi(numStr);
                }
            }
        }
        
        // If no swap was made, return the original number
        return num;
    }
};

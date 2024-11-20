/**
 * @file 02_Customed-Sorted_Array.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief Customed-Sorted Array
 * @version 0.1
 * @date 2024-11-20
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <vector>
using namespace std;

int moves(vector<int> arr) {
    int left = 0, right = arr.size() - 1;
    int swaps = 0;

    while (left < right) {
        // Move left pointer until we find an odd number at the beginning
        while (left < right && arr[left] % 2 == 0) {
            left++;
        }
        
        // Move right pointer until we find an even number at the end
        while (left < right && arr[right] % 2 != 0) {
            right--;
        }

        // Swap the odd number at the beginning with the even number at the end
        if (left < right) {
            swap(arr[left], arr[right]);
            swaps++;
            left++;
            right--;
        }
    }
    
    return swaps;
}

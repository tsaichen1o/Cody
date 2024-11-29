/**
 * @file [MS]0503.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 503. Next Greater Element II
 * @version 0.1
 * @date 2024-11-25
 * https://leetcode.com/problems/next-greater-element-ii/
 * @copyright Copyright (c) 2024
 * 
 */

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> stack;
        vector<int> res(nums.size(), -1);

        for (int i = 0; i < nums.size(); i++) {
            while (!stack.empty() && nums[i] > nums[stack.back()]) {
                res[stack.back()] = nums[i];
                stack.pop_back();
            }
            stack.emplace_back(i);
        }
        for (int num : nums) {
            while (num > nums[stack.back()]) {
                res[stack.back()] = num;
                stack.pop_back();
            }
        }
        return res;
    }
};

int n = nums.size();
    std::stack<int> indexStk;
    std::vector<int> nextBig(n, -1);
    
    for (int i = 0; i < 2 * n; i++) { // Iterate twice to simulate the circular array
        int num = nums[i % n];
        while (!indexStk.empty() && nums[indexStk.top()] < num) {
            nextBig[indexStk.top()] = num;
            indexStk.pop();
        }
        if (i < n) {
            indexStk.push(i);
        }
    }
    return nextBig;

/*
In this solution, the `for` loop runs from `0` to `2 * n` to simulate a circular array. Since the problem is about finding the "next greater element" in a circular manner, it essentially means that if you reach the end of the array and still need to find the next greater value for some element, you need to wrap around and continue from the beginning. By iterating twice (`2 * n`), you effectively look for the next greater value across the entire "circular" array, ensuring all elements are considered. 

The use of `i % n` allows accessing elements circularly, without running out of bounds.
 */

/*
The loop running up to `2 * n` ensures that all elements can be revisited to check for the next greater element. This is necessary because the array is treated as circular, meaning that, for an element towards the end, the next greater element might be near the beginning of the array.

If you only looped from `0` to `n`, some elements at the end of the array would miss the opportunity to find a greater value if it happens to be at the beginning. Therefore, by looping up to `2 * n`, you make sure that all elements have a fair chance to find their next greater value, even when the array wraps around.

If no greater value is found during the loop, the default value of `-1` remains in the `nextBig` vector. This handles cases where there simply isn't a greater value present in the circular sequence.
*/

/*
Looping to `2 * n` will not cause an overflow because the loop index variable (`i`) is used within the bounds of `0` to `2 * n - 1`. The value `2 * n` remains within the limits of the standard integer data type for a typical range of `n` in competitive programming (up to several million). Additionally, within the loop, `nums[i % n]` is used to access elements of the array, which ensures that the index value wraps back to the range `[0, n-1]` and does not exceed array bounds. 

The modulo operator (`%`) is key in ensuring that no out-of-bound array accesses occur, even as `i` continues beyond `n`. The logic safely repeats elements by taking the remainder when divided by `n`, effectively simulating a circular array.
*/
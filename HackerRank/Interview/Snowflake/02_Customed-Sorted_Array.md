To solve the problem where you need to separate even and odd numbers while returning the minimum number of swaps required, an optimal approach can be employed using a two-pointer technique. Here is an efficient solution:

### Explanation:
1. **Two Pointers (`left` and `right`)**:
   - Start with one pointer (`left`) at the beginning of the array and the other pointer (`right`) at the end.
   - The goal is to move `left` to the right until it finds an odd number (that should be at the back).
   - Similarly, move `right` to the left until it finds an even number (that should be at the front).
  
2. **Swapping**:
   - When both conditions are satisfied (odd at the left, even at the right), swap them and increment the swap counter.
  
3. **Time Complexity**:
   - This approach runs in **O(n)** time because both pointers traverse the array once. 
   - The space complexity is **O(1)** as it sorts in place without additional memory, making it optimal for larger arrays.

This approach ensures that all even numbers are placed at the front and odd numbers at the back with the minimum number of swaps.
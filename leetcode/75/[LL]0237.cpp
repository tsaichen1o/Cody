/**
 * @file [LL]0237.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 237. Delete Node in a Linked List
 * @version 0.1
 * @date 2024-12-02
 * 
 * @copyright Copyright (c) 2024
 * 
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        // Copy the value of the next node into the current node
        node->val = node->next->val;
        // Remove the next node
        ListNode* temp = node->next;
        node->next = node->next->next;
        delete temp;  // Free the memory of the removed node
    }
};

/*
Explanation:
Copy Value: Copy the value of node->next into node. This makes node look like the next node.
Skip Next Node: Update node->next to point to node->next->next. This removes the next node from the list.
Delete Node: Finally, delete the temporary pointer (temp) to free up memory.
Complexity:
Time Complexity: O(1), as you only change a few pointers.
Space Complexity: O(1), since no additional space is used.
*/
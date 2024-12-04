/**
 * @file [LL]0019.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 19. Remove Nth Node From End of List
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
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Create a dummy node that points to the head, in case we need to remove the first node.
        ListNode* dummy = new ListNode(0, head);
        
        // Initialize two pointers, `first` and `second`, both starting from `dummy`.
        ListNode* first = dummy;
        ListNode* second = dummy;

        // Move the `first` pointer n+1 steps ahead to create a gap of n nodes between `first` and `second`.
        for (int i = 0; i <= n; ++i) {
            first = first->next;
        }

        // Move `first` to the end, maintaining the gap between `first` and `second`.
        while (first != nullptr) {
            first = first->next;
            second = second->next;
        }

        // `second` is now just before the node to be deleted.
        second->next = second->next->next;

        // Return the updated head, which is `dummy->next`.
        return dummy->next;
    }
};

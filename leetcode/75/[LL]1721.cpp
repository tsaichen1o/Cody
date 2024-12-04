/**
 * @file [LL]1721.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 1721. Swapping Nodes in a Linked List
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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* first = head;
        ListNode* second = head;
        ListNode* current = head;

        // Move `first` to the k-th node from the start.
        for (int i = 1; i < k; i++) {
            first = first->next;
        }

        // Store the k-th node from the start.
        ListNode* kthFromStart = first;

        // Move `first` to the end of the list while moving `second` to the k-th node from the end.
        while (first->next != nullptr) {
            first = first->next;
            second = second->next;
        }

        // Swap the values of the k-th node from the start and the k-th node from the end.
        int temp = kthFromStart->val;
        kthFromStart->val = second->val;
        second->val = temp;

        return head;
    }
};

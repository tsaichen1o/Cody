/**
 * @file [LL]0141.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 141. Linked List Cycle
 * @version 0.1
 * @date 2024-12-04
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
    bool hasCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return false;
        }

        ListNode* slow = head; // Slow pointer moves 1 step at a time.
        ListNode* fast = head; // Fast pointer moves 2 steps at a time.

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;          // Move slow pointer by one step.
            fast = fast->next->next;    // Move fast pointer by two steps.

            if (slow == fast) {
                // If slow and fast pointers meet, there is a cycle.
                return true;
            }
        }

        // If we reach here, there is no cycle.
        return false;
    }
};

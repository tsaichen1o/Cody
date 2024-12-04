/**
 * @file [LL]2095.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 2095. Delete the Middle Node of a Linked List
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
    ListNode* deleteMiddle(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            // If there's only one node or the list is empty, return nullptr.
            return nullptr;
        }

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;

        // Move `fast` two steps at a time, and `slow` one step at a time.
        while (fast != nullptr && fast->next != nullptr) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // `slow` is now pointing to the middle node, and `prev` is the node before `slow`.
        if (prev != nullptr) {
            prev->next = slow->next; // Remove the middle node.
        }

        return head;
    }
};

/*
Explanation:
Base Case: If the list has only one node (head->next == nullptr), return nullptr because deleting the middle node results in an empty list.
Two-Pointer Technique: The fast pointer moves two steps while the slow pointer moves one step. This ensures that when fast reaches the end, slow is at the middle.
Deleting the Middle Node: The prev pointer keeps track of the node before slow. Once slow reaches the middle, prev->next is updated to skip the middle node (slow).
Complexity:
Time Complexity: O(n), where n is the number of nodes in the linked list. This is because we traverse the list once to find the middle.
Space Complexity: O(1), as we are not using any extra space apart from a few pointers.
*/
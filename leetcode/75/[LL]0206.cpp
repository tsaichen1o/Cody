/**
 * @file [LL]0206.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 206. Reverse Linked List
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
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        
        while (curr != nullptr) {
            ListNode* nextTemp = curr->next; // Save the next node
            curr->next = prev; // Reverse the link
            prev = curr; // Move prev up
            curr = nextTemp; // Move to the next node
        }
        
        return prev; // New head of the reversed list
    }
};


/*
Explanation:
prev: Keeps track of the previous node.
curr: Iterates through the current node of the list.
The loop runs until curr becomes nullptr (end of the list).
In each iteration, it:
Saves the next node (nextTemp).
Reverses the link (curr->next = prev).
Moves the pointers (prev and curr) forward.
Finally, returns prev, which points to the new head of the reversed list.
Complexity:
Time Complexity: O(n), where n is the number of nodes in the list.
Space Complexity: O(1), as it is done in-place.
*/
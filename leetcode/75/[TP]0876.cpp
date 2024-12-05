/**
 * @file [TP]0876.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 876. Middle of the Linked List
 * @version 0.1
 * @date 2024-12-05
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
    ListNode* middleNode(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;

        while (fast && fast -> next) {
            fast = fast -> next -> next;
            slow = slow -> next;
        }

        return slow;
    }
};
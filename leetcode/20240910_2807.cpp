/**
 * @file 20240910_2807.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 2807. Insert Greatest Common Divisors in Linked List
 * @version 0.1
 * @date 2024-09-10
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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        // Input: head = [18,6,10,3]
        // Output: [18,6,6,2,10,1,3]
        ListNode* dummy = new ListNode(0, head);
        ListNode* cur = dummy;
        while (cur->next) {
            int gcd = __gcd(cur->next->val, cur->next->next->val);
            if (gcd != 1) {
                cur->next->next = new ListNode(gcd, cur->next->next);
            }
            cur = cur->next;
        }
        return dummy->next;
    }
};

// After inserting a new node (GCD node), the current pointer (cur) should move two steps forward because the newly inserted node will also be part of the linked list.
// In your code, cur moves only one step forward (cur = cur->next;), which will result in revisiting the same node after insertion, causing an infinite loop and thus an MLE.

class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        // Create a dummy node to simplify list manipulations
        ListNode* dummy = new ListNode(0, head);
        ListNode* cur = head;
        
        // Traverse the linked list
        while (cur && cur->next) {
            // Calculate the GCD between current and next node values
            int gcd = __gcd(cur->val, cur->next->val);
            
            // Insert a new node with the GCD value between current and next nodes
            ListNode* gcdNode = new ListNode(gcd, cur->next);
            cur->next = gcdNode;
            
            // Move to the next pair (advance by two nodes)
            cur = gcdNode->next;
        }
        
        // Return the modified list
        return dummy->next;
    }
};

// Advance by Two Steps: After inserting a new node with the GCD value, the current pointer (cur) is moved two steps forward: once to the new GCD node and again to the original next node (cur = gcdNode->next;).
// Base Case Check: We added a check while (cur && cur->next) to ensure that we only calculate the GCD when there are at least two nodes left.
// Efficient GCD Calculation: The standard library function __gcd(a, b) is used for efficient calculation of the greatest common divisor.
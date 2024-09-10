/**
 * @file 20240725_725.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 725. Split Linked List in Parts
 * @version 0.1
 * @date 2024-09-08
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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        // Input: head = [1,2,3,4,5,6,7,8,9,10], k = 3
        // Output: [[1,2,3,4],[5,6,7],[8,9,10]]
        // Given the head of a singly linked list and an integer k, split the linked list into k consecutive linked list parts.
        // The length of each part should be as equal as possible: no two parts should have a size differing by more than one. This may lead to some parts being null.
        // The parts should be in the order of occurrence in the input list, and parts occurring earlier should always have a size greater than or equal to parts occurring later.
        vector<ListNode*> res(k, nullptr);
        int len = 0;
        ListNode* cur = head;
        while (cur) {
            len++;
            cur = cur->next;
        }
        int n = len / k, r = len % k;
        cur = head;
        for (int i = 0; i < k; i++) {
            res[i] = cur;
            for (int j = 0; j < n + (i < r ? 1 : 0) - 1; j++) {
                if (cur) {
                    cur = cur->next;
                }
            }
            if (cur) {
                ListNode* tmp = cur;
                cur = cur->next;
                tmp->next = nullptr;
            }
        }
        return res; 
    }
};

// 
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> res(k, nullptr);
        int len = 0;
        ListNode* currentNode = head;

        // Calculate total length of the list
        while (currentNode) {
            len++;
            currentNode = currentNode->next;
        }

        // Calculate part sizes
        int baseSize = len / k;
        int remainder = len % k;

        currentNode = head;
        for (int i = 0; i < k; i++) {
            res[i] = currentNode;  // Set the current head for this part
            int partSize = baseSize + (i < remainder ? 1 : 0);  // Larger parts come first

            // Traverse the current part
            for (int j = 0; j < partSize - 1; j++) {
                if (currentNode) {
                    currentNode = currentNode->next;
                }
            }

            // Cut the current part from the rest of the list
            if (currentNode) {
                ListNode* nextPartHead = currentNode->next;
                currentNode->next = nullptr;
                currentNode = nextPartHead;
            }
        }

        return res;
    }
};

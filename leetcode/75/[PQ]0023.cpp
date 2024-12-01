/**
 * @file [PQ]0023.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 23. Merge k Sorted Lists
 * @version 0.1
 * @date 2024-11-30
 * https://leetcode.com/problems/merge-k-sorted-lists/
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
#include <queue>

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Define a lambda function for the custom comparator to use in the priority queue
        auto cmp = [](ListNode* a, ListNode* b) {
            return a->val > b->val;
        };

        // Min-heap to store nodes based on value
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);

        // Add the first node of each list to the priority queue
        for (ListNode* list : lists) {
            if (list != nullptr) {
                pq.push(list);
            }
        }

        // Create a dummy node to act as the start of the result list
        ListNode* dummy = new ListNode();
        ListNode* current = dummy;

        // Process nodes from the priority queue
        while (!pq.empty()) {
            ListNode* minNode = pq.top();
            pq.pop();

            // Attach the node to the current position in the result list
            current->next = minNode;
            current = current->next;

            // If the current list has more nodes, add the next node to the priority queue
            if (minNode->next != nullptr) {
                pq.push(minNode->next);
            }
        }

        // Return the next of dummy, as dummy itself is just a placeholder
        return dummy->next;
    }
};

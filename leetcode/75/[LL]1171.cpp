/**
 * @file [LL]1171.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 1171. Remove Zero Sum Consecutive Nodes from Linked List
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
    ListNode* removeZeroSumSublists(ListNode* head) {
        // Dummy node to handle edge cases easily
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        // Hash map to store prefix sum and corresponding node
        unordered_map<int, ListNode*> prefixSumMap;
        prefixSumMap[0] = dummy;

        int prefixSum = 0;
        ListNode* current = dummy;

        // First pass: calculate prefix sum and add nodes to hash map
        while (current != nullptr) {
            prefixSum += current->val;
            prefixSumMap[prefixSum] = current;
            current = current->next;
        }

        prefixSum = 0;
        current = dummy;

        // Second pass: use the prefix sum map to remove zero sum sublists
        while (current != nullptr) {
            prefixSum += current->val;
            current->next = prefixSumMap[prefixSum]->next;
            current = current->next;
        }

        return dummy->next;
    }
};

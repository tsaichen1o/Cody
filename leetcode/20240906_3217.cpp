/**
 * @file 20240906_3217.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 3217. Delete Nodes From Linked List Present in Array
 * @version 0.1
 * @date 2024-09-06
 * 
 * @copyright Copyright (c) 2024
 * 
 */

class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_map<int, int> numMap;
        for (int i = 0; i < nums.size(); i++) {
            numMap[nums[i]] = i;  // Store value as key, index as value
        }
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        while (head) {
            if (numMap.find(head->val) != numMap.end()) {
                prev->next = head->next;
            } else {
                prev = head;
            }
            head = head->next;
        }
        return dummy->next;
    }
};

// use set
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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> numSet(nums.begin(),
                                  nums.end()); // Use a set for quick lookup
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        while (head) {
            if (numSet.find(head->val) != numSet.end()) {
                prev->next = head->next; // Skip the current node
            } else {
                prev = head; // Move prev forward if no removal
            }
            head = head->next;
        }
        return dummy->next;
    }
};

// memory reallocation
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> numSet(nums.begin(), nums.end());  // Use a set for quick lookup
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        while (head) {
            if (numSet.find(head->val) != numSet.end()) {
                prev->next = head->next;
                delete head;  // Free the memory of the removed node
            } else {
                prev = head;
            }
            head = prev->next;
        }
        return dummy->next;
    }
};
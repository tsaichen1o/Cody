/**
 * @file [LL]1474.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 1474. Delete N Nodes After M Nodes of a Linked List
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
    ListNode* deleteNodes(ListNode* head, int m, int n) {
        ListNode* current = head;

        // Iterate through the list while current is not null
        while (current != nullptr) {
            // Keep the first m nodes
            for (int i = 1; i < m && current != nullptr; i++) {
                current = current->next;
            }
            
            // If we reach the end of the list, break
            if (current == nullptr) {
                break;
            }

            // Start deleting the next n nodes
            ListNode* temp = current->next;
            for (int i = 0; i < n && temp != nullptr; i++) {
                ListNode* nextNode = temp->next;
                delete temp;  // Optional: free memory
                temp = nextNode;
            }

            // Connect the m-th node to the node after the deleted nodes
            current->next = temp;
            current = temp;
        }

        return head;
    }
};

/*
Explanation:
Keep the First m Nodes:

Traverse through the list, keeping the first m nodes.
After keeping m nodes, we get a pointer to the m-th node (current).
Delete the Next n Nodes:

Use a temporary pointer (temp) to delete the next n nodes.
Move temp to the next node after each deletion.
Linking:

After deleting the n nodes, link the m-th node (current) to the node after the deleted nodes (temp).
Continue until the end of the list is reached.
Complexity:
Time Complexity: O(N), where N is the number of nodes in the linked list, since we traverse each node at most once.
Space Complexity: O(1), as no additional space is used except for pointers.
*/

class Solution {
public:
    ListNode* deleteNodes(ListNode* head, int m, int n) {
        ListNode* current = head;

        while (current != nullptr) {
            // Keep the first m nodes
            for (int i = 1; i < m && current != nullptr; i++) {
                current = current->next;
            }

            // If we reach the end of the list, break
            if (current == nullptr) {
                break;
            }

            // Start deleting the next n nodes
            ListNode* temp = current->next;
            for (int i = 0; i < n && temp != nullptr; i++) {
                temp = temp->next;
            }

            // Connect the m-th node to the node after the deleted nodes
            current->next = temp;
            current = temp;
        }

        return head;
    }
};

/*
Explanation:
Keep the First m Nodes: The loop iterates through the first m nodes to be kept.
Delete the Next n Nodes: After keeping m nodes, the next n nodes are skipped by moving a temporary pointer (temp) without explicitly deleting nodes.
Link the Remaining Nodes: Once the n nodes are skipped, reconnect the current node to the remaining nodes.
This version is more concise while keeping the operations in place without allocating extra memory for any new data structures.

Complexity:
Time Complexity: O(N), where N is the number of nodes in the linked list.
Space Complexity: O(1), as the list is modified in place and no extra space is used.
*/
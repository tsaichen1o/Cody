/**
 * @file [BST]0450.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 450. Delete Node in a BST
 * @version 0.1
 * @date 2024-11-29
 * 
 * @copyright Copyright (c) 2024
 * 
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        // If root is null, return immediately
        if (!root) {
            return root;
        }

        // If the key to be deleted is smaller than the root's value,
        // then it lies in left subtree
        if (root->val > key) {
            root->left = deleteNode(root->left, key);
            return root;
        }

        // If the key to be deleted is greater than the root's value,
        // then it lies in right subtree
        if (root->val < key) {
            root->right = deleteNode(root->right, key);
            return root;
        }

        // If key is the same as root's value, then this is the node
        // to be deleted

        // Node with only one child or no child
        if (!root->left) {
            return root->right;
        }
        if (!root->right) {
            return root->left;
        }

        // Node with two children: Get the inorder successor (smallest
        // in the right subtree)
        TreeNode* successorNode = root->right;
        while (successorNode->left) {
            successorNode = successorNode->left;
        }

        // Copy the inorder successor's content to this node
        root->val = successorNode->val;
      
        // Delete the inorder successor since its value is now copied 
        root->right = deleteNode(root->right, successorNode->val);

        return root;
    }
};
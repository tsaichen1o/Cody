/**
 * @file [BST]0700.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 700. Search in a Binary Search Tree
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
    TreeNode* searchBST(TreeNode* root, int val) {
        // Base case: If the root is nullptr or the root's value is the one we're searching for
        if (!root || root->val == val) {
            return root;
        }
      
        // If the given value is greater than the root's value, search in the right subtree.
        if (root->val < val) {
            return searchBST(root->right, val);
        }
      
        // If the given value is smaller than the root's value, search in the left subtree.
        return searchBST(root->left, val);
    }
};
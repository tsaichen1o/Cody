/**
 * @file 20241024_0951.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 951. Flip Equivalent Binary Trees
 * @version 0.1
 * @date 2024-10-24
 * https://algo.monster/liteproblems/951
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
    // Check whether two binary trees are flip equivalent.
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        return isFlipEquivalent(root1, root2);
    }

    // Helper function to check recursively if two trees are flip equivalent.
    bool isFlipEquivalent(TreeNode* root1, TreeNode* root2) {
        // If both nodes are null, they are flip equivalent.
        if (root1 == root2) return true;

        // If one of the nodes is null or the values don't match, they aren't flip equivalent.
        if (!root1 || !root2 || root1->val != root2->val) return false;

        // Check if children are flip equivalent in two ways:
        // 1. Without flipping (left with left and right with right) 
        // 2. With flipping (left with right and right with left)
        return (isFlipEquivalent(root1->left, root2->left) && isFlipEquivalent(root1->right, root2->right)) ||
               (isFlipEquivalent(root1->left, root2->right) && isFlipEquivalent(root1->right, root2->left));
    }
};

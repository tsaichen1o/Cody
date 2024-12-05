/**
 * @file [BT]1110.cpp
 * @author auntieyafen (b09705059@gmail.com)
 * @brief 1110. Delete Nodes And Return Forest
 * @version 0.1
 * @date 2024-12-05
 * 
 * @copyright Copyright (c) 2024
 * 
 */

// Definition for a binary tree node.
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

class Solution {
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& toDelete) {
        unordered_set<int> toDeleteSet(toDelete.begin(), toDelete.end()); // Using a set for O(1) lookup.
        vector<TreeNode*> forest;
        
        // Helper function for DFS traversal and deletion.
        root = dfs(root, toDeleteSet, forest);
        if (root) {
            forest.push_back(root); // Add the root if it isn't deleted.
        }
        
        return forest;
    }

private:
    TreeNode* dfs(TreeNode* node, unordered_set<int>& toDeleteSet, vector<TreeNode*>& forest) {
        if (!node) return nullptr; // Base case: if the node is null.

        // Recursively process left and right children.
        node->left = dfs(node->left, toDeleteSet, forest);
        node->right = dfs(node->right, toDeleteSet, forest);

        // If the current node needs to be deleted.
        if (toDeleteSet.count(node->val)) {
            if (node->left) forest.push_back(node->left); // Add left child to forest if it exists.
            if (node->right) forest.push_back(node->right); // Add right child to forest if it exists.
            return nullptr; // Return null to indicate the node should be deleted.
        }
        
        // Return the current node if it's not deleted.
        return node;
    }
};

/*
 * @lc app=leetcode id=226 lang=cpp
 *
 * [226] Invert Binary Tree
 */

// @lc code=start
#include <algorithm>

#include "lib/tree-node.cc"

class Solution {
 public:
  TreeNode* invertTree(TreeNode* root) {
    if (root == nullptr) return root;
    if (root->left != nullptr) invertTree(root->left);
    if (root->right != nullptr) invertTree(root->right);
    std::swap(root->left, root->right);
    return root;
  }
};
// @lc code=end

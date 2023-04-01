/*
 * @lc app=leetcode id=2236 lang=cpp
 *
 * [2236] Root Equals Sum Of Children
 */

// @lc code=start
#include "lib/tree-node.cc"

class Solution {
 public:
  bool checkTree(TreeNode* root) {
    if ((root->left->val) + (root->right->val) == root->val) return true;
    return false;
  }
};
// @lc code=end

/*
 * @lc app=leetcode id=24 lang=cpp
 *
 * [24] Swap Nodes In Pairs
 */

// @lc code=start

#include "../lib/list-node.cc"

class Solution {
 public:
  ListNode* swapPairs(ListNode* head) {
    if (head == nullptr || head->next == nullptr) return head;
    auto continuation = swapPairs(head->next->next);
    auto next = head->next;
    head->next = continuation;
    next->next = head;
    return next;
  }
};// @lc code=end

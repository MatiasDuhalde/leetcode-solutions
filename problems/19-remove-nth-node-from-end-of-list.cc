/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End Of List
 */

// @lc code=start
#include "lib/list-node.cc"

class Solution {
 public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* current_node = head;
    ListNode* parent_of_nth_node = head;
    int depth = 0;
    while (current_node != nullptr) {
      current_node = current_node->next;
      if (depth > n) {
        parent_of_nth_node = parent_of_nth_node->next;
      }
      depth++;
    }
    if (n == depth) {
      return head->next;
    }
    parent_of_nth_node->next = parent_of_nth_node->next->next;
    return head;
  }
};
// @lc code=end

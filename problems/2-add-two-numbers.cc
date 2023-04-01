/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 */

// @lc code=start
#include "lib/list-node.cc"

class Solution {
 public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* current_sum = new ListNode();

    while (l1 != nullptr || l2 != nullptr) {
      if (l1 != nullptr) {
        current_sum->val += l1->val;
        l1 = l1->next;
      }
      if (l2 != nullptr) {
        current_sum->val += l2->val;
        l2 = l2->next;
      }

      // If the sum ends up being greater than 9, we need to carry the 1 to the
      // next digit.
      if (current_sum->val > 9) {
        current_sum->val %= 10;
        current_sum->next = new ListNode();
        current_sum = current_sum->next;
        current_sum->val = 1;
      } else if (l1 != nullptr || l2 != nullptr) {
        current_sum->next = new ListNode();
        current_sum = current_sum->next;
      }
    }
    return current_sum;
  }
};
// @lc code=end

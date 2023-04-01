/*
 * @lc app=leetcode id=876 lang=cpp
 *
 * [876] Middle Of The Linked List
 */

// @lc code=start
#include "lib/list-node.cc"

class Solution {
 public:
  ListNode* middleNode(ListNode* head) {
    int length = 0;
    ListNode* current = head;
    while (current != nullptr) {
      length++;
      current = current->next;
    }
    for (int i = 0; i < length / 2; i++) {
      head = head->next;
    }
    return head;
  }
};// @lc code=end

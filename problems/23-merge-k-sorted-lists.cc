/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge K Sorted Lists
 */

// @lc code=start

#include <vector>

#include "../lib/list-node.cc"

class Solution {
 public:
  ListNode* mergeKLists(std::vector<ListNode*>& lists) {
    ListNode* head = new ListNode();
    ListNode* current = head;
    bool elements_left = true;
    while (elements_left) {
      elements_left = false;
      ListNode** min_element = nullptr;
      for (auto& list : lists) {
        if (list != nullptr) {
          elements_left = true;
          if (min_element == nullptr || list->val < (*min_element)->val) {
            min_element = &list;
          }
        }
      }
      if (min_element != nullptr) {
        current->next = new ListNode((*min_element)->val);
        auto next_in_list = (*min_element)->next;
        if (next_in_list != nullptr) {
          *min_element = next_in_list;
        } else {
          *min_element = nullptr;
        }
        current = current->next;
      }
    }
    return head->next;
  }
};
// @lc code=end

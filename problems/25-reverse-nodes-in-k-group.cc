#include <list>

#include "../lib/list-node.cc"

class Solution {
 public:
  ListNode* reverseKGroup(ListNode* head, int k) {
    if (head == nullptr || head->next == nullptr || k == 1) return head;
    ListNode* current = head;
    std::list<ListNode*> nodes_stack = {head};
    for (int i = 1; i < k; i++) {
      current = current->next;
      if (current == nullptr) return head;
      nodes_stack.push_back(current);
    }
    ListNode* next = current->next;

    ListNode* new_head = nodes_stack.back();
    while (nodes_stack.size() > 1) {
      auto node = nodes_stack.back();
      nodes_stack.pop_back();
      node->next = nodes_stack.back();
    }
    auto continuation = reverseKGroup(next, k);
    head->next = continuation;

    return new_head;
  }
};

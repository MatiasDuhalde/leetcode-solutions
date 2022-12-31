#include "lib/list-node.cc"

class Solution {
 public:
  ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* head = new ListNode();
    ListNode* current = head;
    while (list1 != nullptr || list2 != nullptr) {
      if (list1 == nullptr) {
        current->next = new ListNode(list2->val);
        list2 = list2->next;
      } else if (list2 == nullptr) {
        current->next = new ListNode(list1->val);
        list1 = list1->next;
      } else {
        if (list1->val < list2->val) {
          current->next = new ListNode(list1->val);
          list1 = list1->next;
        } else {
          current->next = new ListNode(list2->val);
          list2 = list2->next;
        }
      }
      current = current->next;
    }
    return head->next;
  }
};

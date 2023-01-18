/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
  ListNode *insertionSortList(ListNode *head) {
    auto current = head;
    ListNode *base = nullptr;
    while (head) {
      current = head;
      head = head->next;
      if (base == nullptr || current->val < base->val) {
        current->next = base;
        base = current;
      } else {
        auto p = base;
        while (p) {
          if (p->next == nullptr || current->val < p->next->val) {
            current->next = p->next;
            p->next = current;
            break;
          }
          p = p->next;
        }
      }
    }
    return base;
  }
};
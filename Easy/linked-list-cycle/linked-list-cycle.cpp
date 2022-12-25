/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
  bool hasCycle(ListNode *head) {
    auto x = head;
    auto y = head;
    while (y && y->next) {
      x = x->next;
      y = y->next->next;
      if (y == nullptr)
        return false;
      if (x == y)
        return true;
    }
    return false;
  }
};
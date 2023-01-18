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
  ListNode *detectCycle(ListNode *head) {
    auto slow = head;
    auto fast = head;
    bool f = true;
    while (fast && fast->next && f) {
      slow = slow->next;
      fast = fast->next->next;
      if (fast == nullptr) {
        return nullptr;
      }
      if (fast == slow) {
        f = false;
      }
    }
    if (f) {
      return nullptr;
    }
    auto current = head;
    while (current != slow) {
      current = current->next;
      slow = slow->next;
    }
    return current;
  }
};
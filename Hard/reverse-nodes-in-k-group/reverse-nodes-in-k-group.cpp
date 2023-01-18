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
  ListNode *reverse(ListNode *head, int k) {
    auto current = head;
    auto cnt = k;
    while (cnt != 0 && current) {
      current = current->next;
      cnt--;
    }
    if (cnt > 0) {
      return head;
    }
    cnt = k;
    auto save = current;
    current = head;
    auto next = head;
    ListNode *previous = nullptr;
    while (cnt-- != 0) {
      next = current->next;
      current->next = previous;
      previous = current;
      current = next;
    }
    head->next = reverse(save, k);
    return previous;
  }

  ListNode *reverseKGroup(ListNode *head, int k) { return reverse(head, k); }
};
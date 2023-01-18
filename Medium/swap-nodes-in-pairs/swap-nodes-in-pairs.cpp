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
  ListNode *swap(ListNode *node) {
    if (node == nullptr || node->next == nullptr) {
      return node;
    }
    auto s1 = node->next;
    auto s2 = s1->next;
    s1->next = node;
    node->next = swap(s2);
    return s1;
  }

  ListNode *swapPairs(ListNode *head) { return swap(head); }
};
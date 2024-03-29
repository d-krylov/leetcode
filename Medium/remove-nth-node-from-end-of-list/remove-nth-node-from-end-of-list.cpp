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
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    int cnt = 0;
    ListNode *cur = head;
    while (cnt != n) {
      cur = cur->next;
      cnt++;
    }
    if (cur == nullptr) {
      return head->next;
    }
    ListNode *res = head;
    while (cur->next != nullptr) {
      cur = cur->next;
      res = res->next;
    }
    res->next = res->next->next;
    return head;
  }
};

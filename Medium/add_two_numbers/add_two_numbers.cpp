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
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *ret = new ListNode();
    int sum = 0;
    auto cur = ret;
    while (l1 || l2) {
      if (l1) {
        sum += l1->val;
        l1 = l1->next;
      }
      if (l2) {
        sum += l2->val;
        l2 = l2->next;
      }
      cur->next = new ListNode(sum % 10);
      sum = (sum > 9) ? 1 : 0;
      cur = cur->next;
    }
    if (sum)
      cur->next = new ListNode(sum);
    return ret->next;
  }
};

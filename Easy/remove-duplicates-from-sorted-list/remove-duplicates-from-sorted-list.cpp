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
  ListNode *deleteDuplicates(ListNode *head) {
    auto curr = head;
    auto save = head;
    if (head == nullptr)
      return head;
    int v = head->val;
    while (curr) {
      if (curr->val != v) {
        save->next = curr;
        v = curr->val;
        save = curr;
      }
      curr = curr->next;
    }
    save->next = nullptr;
    return head;
  }
};

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
  ListNode *removeNodes(ListNode *head) {
    stack<ListNode *> s;
    auto current = head;
    while (current != nullptr) {
      if (s.empty() || current->val <= s.top()->val) {
        s.push(current);
        current = current->next;
      } else {
        s.pop();
        if (s.empty()) {
          head = current;
        } else {
          s.top()->next = current;
        }
      }
    }
    return head;
  }
};
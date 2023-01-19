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
  bool isPalindrome(ListNode *head) {
    auto slow = head;
    auto fast = head;
    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
    }
    auto current = head;
    auto next = head;
    ListNode *previous = nullptr;
    while (current != slow) {
      next = current->next;
      current->next = previous;
      previous = current;
      current = next;
    }
    if (fast) {
      slow = slow->next;
    }
    while (previous && slow) {
      if (previous->val != slow->val) {
        return false;
      }
      previous = previous->next;
      slow = slow->next;
    }
    return true;
  }
};
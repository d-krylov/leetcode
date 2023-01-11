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
  ListNode *merge(ListNode *up, ListNode *down) {
    ListNode *begin = new ListNode();
    auto current = begin;
    while (up && down) {
      if (up->val <= down->val) {
        current->next = up;
        up = up->next;
      } else {
        current->next = down;
        down = down->next;
      }
      current = current->next;
    }
    if (up) {
      current->next = up;
    }
    if (down) {
      current->next = down;
    }
    return begin->next;
  }

  ListNode *sortList(ListNode *head) {

    if (!head || !head->next) {
      return head;
    }

    auto one = head;
    auto two = head;
    ListNode *previous = nullptr;

    while (two && two->next) {
      previous = one;
      one = one->next;
      two = two->next->next;
    }
    previous->next = nullptr;

    auto left = sortList(head);
    auto right = sortList(one);

    return merge(left, right);
  }
};
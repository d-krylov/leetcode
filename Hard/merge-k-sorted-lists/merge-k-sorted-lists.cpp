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
  void Insert(ListNode *l) {
    while (l->next != nullptr && l->val > l->next->val) {
      swap(l->val, l->next->val);
      l = l->next;
    }
  }

  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    auto up = list1;
    auto down = list2;

    if (up == nullptr)
      return down;
    if (down == nullptr)
      return up;

    ListNode *temp;
    while (up != nullptr) {
      if (up->val > down->val) {
        swap(up->val, down->val);
      }
      Insert(down);
      temp = up;
      up = up->next;
    }
    temp->next = down;
    return list1;
  }

  ListNode *mergeKLists(vector<ListNode *> &lists) {
    auto sz = lists.size();
    int interval = 1;
    while (interval < sz) {
      for (int i = 0; i < sz - interval; i += interval * 2) {
        lists[i] = mergeTwoLists(lists[i], lists[i + interval]);
      }
      interval *= 2;
    }
    if (sz > 0)
      return lists[0];
    return nullptr;
  }
};

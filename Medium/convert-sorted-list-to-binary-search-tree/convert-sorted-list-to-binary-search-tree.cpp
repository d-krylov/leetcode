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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
  TreeNode *sortedListToBST(ListNode *&node, int n) {
    if (n <= 0) {
      return nullptr;
    }
    auto left = sortedListToBST(node, n / 2);
    auto root = new TreeNode(node->val);
    root->left = left;
    node = node->next;
    root->right = sortedListToBST(node, n - n / 2 - 1);
    return root;
  }

  TreeNode *sortedListToBST(ListNode *head) {
    auto current = head;
    int n = 0;
    while (current) {
      current = current->next;
      n++;
    }
    auto root = sortedListToBST(head, n);
    return root;
  }
};
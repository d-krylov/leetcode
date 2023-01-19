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
  bool dfs(ListNode *list_node, TreeNode *tree_node) {
    if (list_node == nullptr) {
      return true;
    }
    if (tree_node == nullptr) {
      return false;
    }
    bool x = false;
    if (tree_node->val == list_node->val) {
      x = dfs(list_node->next, tree_node->left);
      x |= dfs(list_node->next, tree_node->right);
    }
    return x;
  }

  bool Is(ListNode *head, TreeNode *root) {
    if (root == nullptr) {
      return false;
    }
    return dfs(head, root) || Is(head, root->left) || Is(head, root->right);
  }

  bool isSubPath(ListNode *head, TreeNode *root) { return Is(head, root); }
};
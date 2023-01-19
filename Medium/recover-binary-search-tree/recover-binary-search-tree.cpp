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
  TreeNode *first = nullptr;
  TreeNode *second = nullptr;
  void inorder(TreeNode *node, TreeNode *&previous) {
    if (node == nullptr) {
      return;
    }
    inorder(node->left, previous);
    if (previous && (node->val < previous->val)) {
      if (first == nullptr) {
        first = previous;
      }
      second = node;
    }
    previous = node;
    inorder(node->right, previous);
  }

  void recoverTree(TreeNode *root) {
    TreeNode *previous = nullptr;
    inorder(root, previous);
    swap(first->val, second->val);
  }
};
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
  int deep(TreeNode *node, bool &f) {
    if (node == nullptr) {
      return 0;
    }
    auto deep_left = deep(node->left, f);
    auto deep_right = deep(node->right, f);
    if (abs(deep_left - deep_right) > 1) {
      f = false;
    }
    return max(deep_left, deep_right) + 1;
  }

  bool isBalanced(TreeNode *root) {
    bool f = true;
    auto d = deep(root, f);
    return f;
  }
};
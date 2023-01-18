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
  TreeNode *invert(TreeNode *node) {
    if (!node) {
      return nullptr;
    }
    if (!node->left && !node->right) {
      return node;
    }
    auto left = invertTree(node->left);
    auto right = invertTree(node->right);
    node->right = left;
    node->left = right;
    return node;
  }

  TreeNode *invertTree(TreeNode *root) { return invert(root); }
};
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
  int maxDepth(TreeNode *root, int deep) {
    if (root->left == nullptr && root->right == nullptr)
      return deep;
    int l = 0;
    int r = 0;
    if (root->left)
      l = maxDepth(root->left, deep + 1);
    if (root->right)
      r = maxDepth(root->right, deep + 1);
    return max(l, r);
  }

  int maxDepth(TreeNode *root) {
    if (!root)
      return 0;
    return maxDepth(root, 1);
  }
};
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
  int dfs(TreeNode *node, int &value) {
    if (!node) {
      return 0;
    }
    int lhs = max(0, dfs(node->left, value));
    int rhs = max(0, dfs(node->right, value));
    value = max(value, node->val + lhs + rhs);
    return max(lhs, rhs) + node->val;
  }

  int maxPathSum(TreeNode *root) {
    int value = root->val;
    dfs(root, value);
    return value;
  }
};
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
  int dfs(TreeNode *node, int &size) {
    if (node == nullptr) {
      return size;
    }
    int x = dfs(node->left, size);
    int y = dfs(node->right, size);
    x = (node->left && node->val == node->left->val) ? x : 0;
    y = (node->right && node->val == node->right->val) ? y : 0;
    size = max(size, x + y);
    return max(x, y) + 1;
  }

  int longestUnivaluePath(TreeNode *root) {
    int ret = INT_MIN;
    dfs(root, ret);
    return ret != INT_MIN ? ret : 0;
  }
};
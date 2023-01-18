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
  TreeNode *merge(TreeNode *n1, TreeNode *n2) {
    TreeNode *node;
    if (n1 && n2) {
      node = n1;
      node->val = n1->val + n2->val;
      node->left = merge(n1->left, n2->left);
      node->right = merge(n1->right, n2->right);
    } else if (n1) {
      node = n1;
    } else if (n2) {
      node = n2;
    }
    return node;
  }

  TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2) {
    return merge(root1, root2);
  }
};
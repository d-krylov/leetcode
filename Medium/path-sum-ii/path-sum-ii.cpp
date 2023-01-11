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
  void deep(TreeNode *node, vector<vector<int>> &ret, vector<int> &v, int sum) {
    if (node == nullptr) {
      return;
    }
    v.push_back(node->val);

    if (node->val == sum && node->left == nullptr && node->right == nullptr) {
      ret.push_back(v);
    } else {
      deep(node->left, ret, v, sum - node->val);
      deep(node->right, ret, v, sum - node->val);
    }
    v.pop_back();
  }

  vector<vector<int>> pathSum(TreeNode *root, int targetSum) {
    vector<vector<int>> ret;
    vector<int> v;
    deep(root, ret, v, targetSum);
    return ret;
  }
};
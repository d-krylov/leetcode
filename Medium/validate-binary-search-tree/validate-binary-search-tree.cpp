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
  bool isValidBST(TreeNode *node, int &Max, int &Min) {
    if (node->left == nullptr && node->right == nullptr) {
      Max = node->val;
      Min = node->val;
      return true;
    }
    int current_max;
    int current_min;

    if (node->left) {
      auto left_ret = isValidBST(node->left, current_max, current_min);
      if (left_ret == false) {
        return false;
      }
      if (node->val <= current_max) {
        return false;
      }
      Min = min(current_min, node->val);
    } else {
      Min = node->val;
    }
    if (node->right) {
      auto right_ret = isValidBST(node->right, current_max, current_min);
      if (right_ret == false) {
        return false;
      }
      if (node->val >= current_min) {
        return false;
      }
      Max = max(current_max, node->val);
    } else {
      Max = node->val;
    }
    return true;
  }

  bool isValidBST(TreeNode *root) {
    int Max;
    int Min;
    return isValidBST(root, Max, Min);
  }
};
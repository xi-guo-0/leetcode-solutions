#include <iostream>
#include <ostream>
#include <sstream>
#include <string>

using namespace std;

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

ostream &operator<<(ostream &out, TreeNode *root) {
  if (root) {
    out << root->val;
    if (root->left || root->right) {
      out << '(';
    }
    if (root->left) {
      out << root->left;
    }
    if (root->left || root->right) {
      out << ')';
    }
    if (root->right) {
      out << '(';
      out << root->right;
      out << ')';
    }
  }
  return out;
}

class Solution {
public:
  string tree2str(TreeNode *root) {
    ostringstream oss;
    oss << root;
    return oss.str();
  }
};

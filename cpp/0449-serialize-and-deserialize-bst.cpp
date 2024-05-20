/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
  // Encodes a tree to a single string.
  string serialize(TreeNode *root) {
    ostringstream os;
    buildString(root, os);
    return os.str();
  }

  // Decodes your encoded data to tree.
  TreeNode *deserialize(string data) {
    istringstream is(data);
    return buildTree(is);
  }

private:
  const string sp = " ";
  const string np = "n";

  void buildString(TreeNode *root, ostringstream &os) {
    if (root == nullptr) {
      os << np << sp;
    } else {
      os << to_string(root->val) << sp;
      buildString(root->left, os);
      buildString(root->right, os);
    }
  }

  TreeNode *buildTree(istringstream &is) {
    string val = "";
    is >> val;
    if (val == np)
      return nullptr;
    TreeNode *node = new TreeNode(stoi(val));
    node->left = buildTree(is);
    node->right = buildTree(is);
    return node;
  }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

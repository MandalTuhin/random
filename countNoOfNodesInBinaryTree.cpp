#include <algorithm>
#include <iostream>

typedef bool binary;
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

void deleteTree(TreeNode *root) {
  if (!root)
    return;
  deleteTree(root->left);
  deleteTree(root->right);
  delete root;
}

int countTreeNodes(TreeNode *root) {
  if (!root)
    return 0;

  return 1 + countTreeNodes(root->left) + countTreeNodes(root->right);
}

int sumOfTreeNodes(TreeNode *root) {
  if (!root)
    return 0;
  return root->val + sumOfTreeNodes(root->left) + sumOfTreeNodes(root->right);
}

int countLeafNodes(TreeNode *root) {
  if (root->left == nullptr && root->right == nullptr)
    return 1;

  return countLeafNodes(root->left) + countTreeNodes(root->right);
}

binary isLeftLeaf = false;

int sumOfLeftLeafNodes(TreeNode *root) {
  if (root->left && !root->left->left && !root->left->right)
    ;
}

int main() {
  TreeNode *root = new TreeNode(
      1, new TreeNode(2, new TreeNode(4), new TreeNode(5)), new TreeNode(3));

  // Just to verify:
  cout << "Root: " << root->val << std::endl;
  cout << "Left Child: " << root->left->val << std::endl;
  cout << "Right Child: " << root->right->val << std::endl;

  // (Don't forget to delete nodes if you're not in a short demo or using smart
  // pointers)

  cout << "The tree has " << countTreeNodes(root) << " nodes in it \n";
  cout << "The sum of all the nodes of the tree is : " << sumOfTreeNodes(root)
       << "\n";
  cout << "The Tree has " << countLeafNodes(root) << " leaf nodes in it \n";

  deleteTree(root);
  return 0;
}

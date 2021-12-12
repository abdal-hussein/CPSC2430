// Sheng Xu
// lab 3
// 2021/10/8
// lab3.cpp

#include <iostream>

using namespace std;

class BST {
private:
  struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
  };
  TreeNode* root;

  // Function for inserting a new node to a tree
  TreeNode* insert(TreeNode* t, int x) {
    if (!t) {
      // Determine whether the current node is empty,
      // if it is empty, create a new node and return it.
      TreeNode* newNode = new TreeNode;
      newNode->val = x;
      newNode->left = NULL;
      newNode->right = NULL;
      return newNode;
    }
    // If the current node value is greater than x,
    // call the recursive function on the left child node.
    if (x < t->val) t->left = insert(t->left, x);
    // If the current node value is less than x,
    // call the recursive function on the right child node.
    else t->right = insert(t->right, x);
    return t;
  }

  // Function for inorder traversal
  void inorder(TreeNode* t) {
    if (!t) return;
    inorder(t->left);
    cout << t->val << " ";
    inorder(t->right);
  }

  // Function for preorder traversal
  void preorder(TreeNode* t) {
    if (!t) return;
    cout << t->val << " ";
    preorder(t->left);
    preorder(t->right);
  }

  // Function for postorder traversal
  void postorder(TreeNode* t) {
    if (!t) return;
    postorder(t->left);
    postorder(t->right);
    cout << t->val << " ";
  }

public:
  BST() {
    root = NULL;
  }
  void insertNode(int x) {
    root = insert(root, x);
  }
  void inorderDisplay() {
    inorder(root);
  }
  void preorderDisplay() {
    preorder(root);
  }
  void postorderDisplay() {
    postorder(root);
  }
};

int main() {
  BST t;
  // Insert
  t.insertNode(10);
  t.insertNode(7);
  t.insertNode(29);
  t.insertNode(30);
  t.insertNode(9);
  t.insertNode(54);
  t.insertNode(2);
  t.insertNode(6);
  t.insertNode(13);
  t.insertNode(17);

  // Inorder display
  cout << "The inorder traversal outcome is: ";
  t.inorderDisplay();
  cout << endl;

  // Preorder display
  cout << "The preorder traversal outcome is: ";
  t.preorderDisplay();
  cout << endl;

  // Postorder display
  cout << "The postorder traversal outcome is: ";
  t.postorderDisplay();
  cout << endl;

  return 0;
}
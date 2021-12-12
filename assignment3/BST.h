// Sheng Xu
// assignment 3
// 2021/10/15
// BST.h

#pragma once

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

  TreeNode* insert(TreeNode* r, int key);
  int search(TreeNode* r, int key);
  int successor(TreeNode* r, int key);
  int predecessor(TreeNode* r, int key);
  int height(TreeNode* r);
  int size(TreeNode* r);
  TreeNode* delete_node(TreeNode* r, int key);
  void inorder(TreeNode* r);
  void preorder(TreeNode* r);
  void postorder(TreeNode* r);
  int balance(TreeNode* r);
  TreeNode* destroy(TreeNode* r);
 public:
  BST() {
    root = nullptr;
  }
  void insertNode(int x) {
    root = insert(root, x);
  }
  int searchNode(int x) {
    return search(root, x);
  }
  int successorNode(int x) {
    return successor(root,x);
  }
  int predecessorNode(int x) {
    return predecessor(root, x);
  }
  int heightTree() {
    return height(root);
  }
  int sizeTree() {
    return size(root);
  }
  void deleteNode(int x) {
    root = delete_node(root, x);
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
  int balanceTree() {
    return balance(root);
  }
  TreeNode* destroyTree() {
    root = destroy(root);
    return root;
  }
};


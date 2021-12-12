// Sheng Xu
// assignment 3
// 2021/10/15
// BST.cpp

#include "BST.h"

// Function for inserting a new node to the tree
BST::TreeNode* BST::insert(TreeNode* r, int key) {
  if (!r) {
    // Determine whether the current tree is empty,
    // if it is empty, create a new node and return it.
    TreeNode* newNode = new TreeNode;
    newNode->val = key;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
  }
  // If the current node value is greater than the key,
  // call the recursive function on the left child node.
  if (key < r->val) r->left = insert(r->left, key);
  // If the current node value is less than the key,
  // call the recursive function on the right child node.
  else r->right = insert(r->right, key);
  return r;
}

// Function for searching a value from the tree
int BST::search(TreeNode* r, int key) {
  // Base case
  if (!r) return -1;
  if (key == r->val) return 1;
  // Recursion
  return (key < r->val) ? search(r->left, key) : search(r->right, key);
}

// Function for finding the successor for a given value
int BST::successor(TreeNode* r, int key) {
  TreeNode* successor = nullptr;
  TreeNode* indexNode = r;
  while (key != indexNode->val) {
    // If key is less than the index node's value,
    // go to left sub tree and update the successor pointer.
    if (key < indexNode->val) {
      successor = indexNode;
      indexNode = indexNode->left;
    }
    // If key is greater than the index node's value,
    // go to right sub tree, but there is no need to update the successor pointer.
    else indexNode = indexNode->right;
  }
  // check if the index node has right sub tree,
  // if yes then update the successor to "the most left" node of the right sub tree.
  if (indexNode && indexNode->right) {
    indexNode = indexNode->right;
    while (indexNode->left) indexNode = indexNode->left;
    successor = indexNode;
  }
  // The case that the node has no successor
  if (successor == nullptr) {
    cout << "None ";
    return 0;
  }
  return successor->val;
}

// Function for finding the predecessor for a given value
int BST::predecessor(TreeNode* r, int key) {
  TreeNode* predecessor = nullptr;
  TreeNode* indexNode = r;
  while (key != indexNode->val) {
    // If key is greater than the index node's value,
    // go to right sub tree and update the predecessor pointer.
    if (key > indexNode->val) {
      predecessor = indexNode;
      indexNode = indexNode->right;
    }
    // If key is less than the index node's value,
    // go to left sub tree, but there is no need to update the predecessor pointer.
    else indexNode = indexNode->left;
  }
  // Check if the index node has left sub tree,
  // if yes then update the predecessor to "the most right" node of the left sub tree.
  if (indexNode && indexNode->left) {
    indexNode = indexNode->left;
    while (indexNode->right) indexNode = indexNode->right;
    predecessor = indexNode;
  }
  // The case that the node has no predecessor
  if (predecessor == nullptr) {
    cout << "None ";
    return 0;
  }
  return predecessor->val;
}

// Function for finding the height of the tree
int BST::height(TreeNode* r) {
  // Base case
  if (!r) return 0;
  // Recursion
  return 1 + max(height(r->left), height(r->right));
}

// Function for getting the number of nodes of the tree
int BST::size(TreeNode* r) {
  // Base case
  if (!r) return 0;
  // Recursion
  return size(r->left) + 1 + size(r->right);
}

// Function for deleting a node of the tree based on the key
BST::TreeNode* BST::delete_node(TreeNode* r, int key) {
  if (!r) return nullptr;
  if (r->val > key) r->left = delete_node(r->left, key);
  else if (r->val < key) r->right = delete_node(r->right, key);
  // Locate the node based on the key
  else {
    // If the node doesn't have two children,
    // update the node to its child, or update to nullptr.
    if (!r->left || !r->right) r = (r->left) ? r->left : r->right;
    else {
      // If the node have two children,
      // find "the most right" node of the left sub tree,
      // assign the value of it to the root of this recusive round,
      // and then delete the node of the left sub tree using recursive call.
      TreeNode* currentNode = r->left;
      while (currentNode->right) currentNode = currentNode->right;
      r->val = currentNode->val;
      r->left = delete_node(r->left, currentNode->val);
    }
  }
  return r;
}

// Function for inorder traversal
void BST::inorder(TreeNode* r) {
  if (!r) return;
  inorder(r->left);
  cout << r->val << " ";
  inorder(r->right);
}

// Function for preorder traversal
void BST::preorder(TreeNode* r) {
  if (!r) return;
  cout << r->val << " ";
  preorder(r->left);
  preorder(r->right);
}

// Function for postorder traversal
void BST::postorder(TreeNode* r) {
  if (!r) return;
  postorder(r->left);
  postorder(r->right);
  cout << r->val << " ";
}

// Function for balance check
int BST::balance(TreeNode* r) {
  // Base case
  if (!r) return 1;
  if (abs(height(r->left) - height(r->right)) > 1) return -1;
  // Recursion
  return min(balance(r->left), balance(r->right));
}

// Function for destroying the tree
BST::TreeNode* BST::destroy(TreeNode* r) {
  if (r) {
    r->left = destroy(r->left);
    r->right = destroy(r->right);
    delete r;
    r = nullptr;
  }
  return r;
}

// Sheng Xu
// assignment 3
// 2021/10/15
// assignment3.cpp

#include "BST.h"

int main() {
  BST b;             // Declare a BST object b
  int choice;        // User's choice
  int key;           // Generic TreeNode's key
  // User interface
  cout << "Welcome to my implementation of BST." << endl;
 begin:
  cout << "Please choose the operation you want:" << endl;
  cout << "1. Insert a node" << endl;
  cout << "2. Search a value" << endl;
  cout << "3. Find the successor for a given value" << endl;
  cout << "4. Find the predecessor for a given value" << endl;
  cout << "5. Find the height of the tree" << endl;
  cout << "6. Get the number of nodes in the tree" << endl;
  cout << "7. Delete a node" << endl;
  cout << "8. Traverse the tree inorder" << endl;
  cout << "9. Traverse the tree preorder" << endl;
  cout << "10. Traverse the tree postorder" << endl;
  cout << "11. Balance check" << endl;
  cout << "12. Destory the tree" << endl;
  cout << "0. Quit the system" << endl;
  cin >> choice;

  switch(choice) {
  case 1:
    cout << "Please type a value you want to insert: ";
  type:
    cin >> key;
    if (b.searchNode(key) == 1) {
      cout << "We do not accept duplicate values. Please re-enter: ";
      goto type;
    }
    b.insertNode(key);
    cout << "You have successfully inserted a node." << endl << endl;
    goto begin;
  case 2:
    cout << "Please type a value you want to search: ";
    cin >> key;
    if (b.searchNode(key) == -1) cout << "The value is not in the BST." << endl << endl;
    else cout << "The value is in the BST." << endl << endl;
    goto begin;
  case 3:
    cout << "Please type a value which you want to find its successor: ";
    cin >> key;
    cout << "Its successor node's value is " << b.successorNode(key) << "." << endl << endl;
    goto begin;
  case 4:
    cout << "Please type a value which you want to find its predecessor: ";
    cin >> key;
    cout << "Its predecessor node's value is " << b.predecessorNode(key) << "." << endl << endl;
    goto begin;
  case 5:
    cout << "The height of the tree is " << b.heightTree() << "." << endl << endl;
    goto begin;
  case 6:
    cout << "The number of nodes in the tree is " << b.sizeTree() << "." << endl << endl;
    goto begin;
  case 7:
    cout << "Please type a TreeNode's value you want to delete: ";
    cin >> key;
    b.deleteNode(key);
    cout << "The TreeNode has been successfully deleted." << endl << endl;
    goto begin;
  case 8:
    cout << "The inorder traversal outcome of the tree is: " << endl;
    b.inorderDisplay();
    cout << endl << endl;
    goto begin;
  case 9:
    cout << "The preorder traversal outcome of the tree is: " << endl;
    b.preorderDisplay();
    cout << endl << endl;
    goto begin;
  case 10:
    cout << "The postorder traversal outcome of the tree is: " << endl;
    b.postorderDisplay();
    cout << endl << endl;
    goto begin;
  case 11:
    if (b.balanceTree() == -1) cout << "The tree is not balanced." << endl << endl;
    else cout << "The tree is balanced." << endl << endl;
    goto begin;
  case 12:
    if (b.destroyTree() == nullptr) cout << "The tree has been destroyed successfully." << endl << endl;
    goto begin;
  case 0:
    cout << "Goodbye!" << endl;
    break;
  default:
    cout << "Goodbye!" << endl;
    break;
  }
  return 0;
}

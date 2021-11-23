#include <bits/stdc++.h>

using namespace std;

class Node {
 public:
  int data;
  Node* right;
  Node* left;
  Node(int data) {
    this->data = data;
    right = left = NULL;
  }
};

// PreOrder build of tree root,left,right
Node* buildTree(int* arr, int size) {
  static int i = 0;
  if (i >= size) return NULL;
  if (arr[i] == -1) return NULL;
  Node* x = new Node(arr[i]);
  i++;
  x->left = buildTree(arr, size);
  i++;
  x->right = buildTree(arr, size);
  return x;
}
void printPreOrder(Node* root) {
  if (root == NULL) return;
  cout << root->data << " ";
  printPreOrder(root->left);
  printPreOrder(root->right);
}
void printInOrder(Node* root) {
  if (root == NULL) return;
  printInOrder(root->left);
  cout << root->data << " ";
  printInOrder(root->right);
}
void printPostOrder(Node* root) {
  if (root == NULL) return;
  printPostOrder(root->left);
  printPostOrder(root->right);
  cout << root->data << ' ';
}

int main() {
  int arr[] = {1, 2, 4, -1, -1, 5, 7, -1, -1, -1, 3, -1, 6, -1, -1};
  int size = sizeof(arr) / sizeof(int);
  Node* root = buildTree(arr, size);
  printPreOrder(root);
  cout << endl;
  printInOrder(root);
  cout << endl;
  printPostOrder(root);
}
#include <bits/stdc++.h>
using namespace std;

class Node {
 public:
  int data;
  Node* right;
  Node* left;
  Node(int x) {
    data = x;
    right = left = NULL;
  }
};

Node* insertBST(Node* root, int key) {
  if (root == NULL) return new Node(key);
  if (key <= root->data)
    root->left = insertBST(root->left, key);
  else
    root->right = insertBST(root->right, key);
  return root;
}

void preOrder(Node* root) {
  if (root == NULL) return;
  preOrder(root->left);
  cout << root->data << " ";
  preOrder(root->right);
}

bool search(Node* root, int key) {
  if (root == NULL) return false;
  if (root->data == key)
    return true;
  else if (root->data > key)
    return search(root->left, key);
  else
    return search(root->right, key);
}
Node* successor(Node* root) {
  while (root->left != NULL) root = root->left;
  return root;
}
Node* remove(Node* root, int key) {
  if (root == NULL) return NULL;
  if (key < root->data)
    root->left = remove(root->left, key);
  else if (key > root->data)
    root->right = remove(root->right, key);
  else {
    if (root->left == NULL and root->right == NULL) {
      Node* temp = root;
      delete temp;
      root = NULL;
    } else if (root->left == NULL) {
      Node* temp = root;
      root = root->right;
      delete temp;
    } else if (root->right == NULL) {
      Node* temp = root;
      root = root->left;
      delete temp;
    } else {
      Node* temp = successor(root->right);
      root->data = temp->data;
      root->right = remove(root->right, temp->data);
    }
  }
  return root;
}

void printInRange(Node* root, int x1, int x2) {
  if (root == NULL)
    return;  // I am so fucked I always write root = NULL to check
  if (root->data >= x1 and root->data <= x2) {
    printInRange(root->left, x1, x2);
    cout << root->data << ' ';
    printInRange(root->right, x1, x2);
  } else if (root->data > x2)
    printInRange(root->left, x1, x2);
  else
    printInRange(root->right, x1, x2);
}

void rootToLeaf(Node* root, vector<int>& x) {
  if (root == NULL) return;
  if (root->left == NULL and root->right == NULL) {
    for (auto i : x) cout << i << "->";
    cout << root->data;
    cout << endl;
  }
  x.push_back(root->data);
  rootToLeaf(root->left, x);
  rootToLeaf(root->right, x);
  x.pop_back();
}

int main() {
  Node* root = NULL;
  int arr[] = {8, 3, 10, 1, 6, 14, 4, 7, 13};
  for (int x : arr) {
    root = insertBST(root, x);
  }
  preOrder(root);
  cout << endl;
  root = remove(root, 14);
  preOrder(root);
  cout << endl;
  printInRange(root, 3, 6);
  vector<int> x;
  cout << endl;
  rootToLeaf(root, x);

  // cout << search(root, 13);
}
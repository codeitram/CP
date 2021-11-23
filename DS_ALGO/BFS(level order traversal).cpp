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

Node* buildTreeInorder(int* arr, int size) {
  int i = 0;
  Node* root = new Node(arr[i]);
  queue<Node*> q;
  q.push(root);
  while (!q.empty() and i < size) {
    i++;
    int temp = arr[i];
    if (temp != -1) {
      Node* x1 = new Node(temp);
      q.front()->left = x1;
      q.push(x1);
    }

    i++;
    temp = arr[i];
    if (temp != -1) {
      Node* x2 = new Node(temp);
      q.front()->right = x2;
      q.push(x2);
    }
    q.pop();
  }
  return root;
}

void BFS(Node* root) {
  queue<Node*> q;
  q.push(root);
  q.push(NULL);

  while (!q.empty()) {
    Node* temp = q.front();
    q.pop();
    if (temp == NULL) {
      cout << '\n';
      if (!q.empty())
        q.push(NULL);  // if you push without checking infinte loop
    } else {
      if (temp->left)
        q.push(temp->left);  // if you push without checking infinite loop
      if (temp->right) q.push(temp->right);
      cout << temp->data << ' ';
    }
  }
}

int heightOfTree(Node* root) {
  if (root == NULL) return 0;
  int a = heightOfTree(root->left);
  int b = heightOfTree(root->right);
  return 1 + max(a, b);
}

int diameter(Node* root) {  // TC = N^2
  if (root == NULL) return 0;
  int D1 = heightOfTree(root->left) + heightOfTree(root->right);
  int D2 = diameter(root->left);
  int D3 = diameter(root->right);
  return max(D1, max(D2, D3));
}

// Diameter optimized approach
class hdpair {
 public:
  int h;
  int d;
};

hdpair diameterOptimized(Node* root) {
  hdpair base;
  if (root == NULL) {
    base.h = base.d = 0;
    return base;
  }
  hdpair l = diameterOptimized(root->left);
  hdpair r = diameterOptimized(root->right);

  base.h = 1 + max(l.h, r.h);

  base.d = max(l.h + r.h, max(l.d, r.d));
  return base;
}

int main() {
  // int arr[] = {1, 2, 4, -1, -1, 5, 7, -1, -1, -1, 3, -1, 6, -1, -1};
  // int size = sizeof(arr) / sizeof(int);
  // Node* root = buildTree(arr, size);
  int arr[] = {1, 2, 3, 4, 5, -1, 6, -1, -1, 7, -1, -1, -1, -1, -1};
  int size = sizeof(arr) / sizeof(int);
  Node* root = buildTreeInorder(arr, size);
  cout << "height of Tree: " << heightOfTree(root) << '\n';
  cout << "Diameter of Tree: " << diameter(root) << '\n';
  cout << "Diameter of Tree: " << diameterOptimized(root).d << '\n';
  BFS(root);
}
#include <bits/stdc++.h>
using namespace std;

class Node {
 public:
  char data;
  unordered_map<char, Node *> map;
  bool isTerminal;

  Node(char data) {
    this->data = data;
    isTerminal = false;
  }
};

class Trie {
  Node *root;

 public:
  Trie() { root = new Node('\0'); }

  void insert(string word) {
    Node *temp = root;
    for (auto a : word) {
      if (temp->map.count(a) == 0) {
        temp->map[a] = new Node(a);
      }
      temp = temp->map[a];
    }
    temp->isTerminal = true;
  }

  bool search(string word) {
    Node *temp = root;
    for (char a : word) {
      if (temp->map.count(a) == 0)
        return false;
      else
        temp = temp->map[a];
    }
    return temp->isTerminal;
  }

  Node *searchThenReturnNode(string word) {
    Node *temp = root;
    Node *tempPrev = NULL;
    int i = 0;
    int ic = 0;
    for (; word[i] != '\0'; i++) {
      char a = word[i];
      temp = temp->map[a];
    }
    return temp;
  }

  void remove(string word) {
    bool isPresent = search(word);
    if (!isPresent) return;

    Node *x = searchThenReturnNode(word);
    if (x->isTerminal) {
      x->isTerminal = false;
      // recursiveDelete(root, word, 0);
      // Write the function to clear the memory too
    }
  }
};
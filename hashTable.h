#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Node {
 public:
  string key;
  T value;
  Node* next;
  Node(string key, T value) {
    this->key = key;
    this->value = value;
    next = NULL;
  }
  ~Node() {
    if (next != NULL) delete next;
  }
};

template <typename T>
class hashTable {
 private:
  Node<T>** table;
  int cs, ts;

  int hashk(string key) {
    int power = 1;
    int idx = 0;
    for (auto a : key) {
      idx = (idx + a * power) % ts;
      power = (power * 29) % ts;
    }
    return idx;
  }

  void rehash() {
    Node<T>** tableC = table;
    int tsC = ts;
    cs = 0;
    ts = 2 * ts + 1;
    table = new Node<T>*[ts];
    for (int i = 0; i < ts; i++) {
      table[i] = NULL;
    }

    for (int i = 0; i < tsC; i++) {
      Node<T>* temp = tableC[i];
      while (temp) {
        insert(temp->key, temp->value);
        temp = temp->next;
      }
      if (tableC[i]) delete tableC[i];
    }
    delete[] tableC;
  }

 public:
  hashTable(int default_size = 7) {
    ts = default_size;
    cs = 0;
    table = new Node<T>*[default_size];
    for (int i = 0; i < default_size; i++) table[i] = NULL;
  }
  void insert(string key, T value) {
    int idx = hashk(key);
    Node<T>* x = new Node<T>(key, value);

    // insert at head of link list
    x->next = table[idx];
    table[idx] = x;
    cs++;

    float load_factor = cs / float(ts);
    if (load_factor > .7) {
      rehash();
    }
  }

  void remove(string key) {
    int idx = hashk(key);

    Node<T>* temp = table[idx];
    Node<T>* prev = NULL;

    if (temp && temp->key == key) {
      Node<T>* del = temp;
      table[idx] = temp->next;
      del->next = NULL;
      delete del;
    }
    while (temp && temp->key != key) {
      prev = temp;
      temp = temp->next;
    }
    if (temp == NULL) return;
    prev->next = temp->next;
    temp->next = NULL;
    delete temp;
  }
  T& operator[](string key) {
    T* valuefound = search(key);
    if (valuefound == NULL) {
      T randObj;
      insert(key, randObj);
      valuefound = search(key);
    }
    return *valuefound;
  }

  // why search is returning a poitner and not data ? (see if you remember)
  T* search(string key) {
    int idx = hashk(key);
    Node<T>* temp = table[idx];
    while (temp) {
      if (temp->key == key)
        return &temp->value;
      else
        temp = temp->next;
    }
    return NULL;
  }

  // Or another way to search is by Checking is present and then calling search
  bool isPresent(string key) {
    int idx = hashk(key);
    Node<T>* temp = table[idx];
    while (temp) {
      if (temp->key == key) return true;
      temp = temp->next;
    }
    return false;
  }

  T search2(string key) {
    int idx = hashk(key);
    Node<T>* temp = table[idx];
    while (temp) {
      if (temp->key == key)
        return temp->value;
      else
        temp = temp->next;
    }
  }

  // not part of stl,, we are using to check our program in here
  void print() {
    for (int i = 0; i < ts; i++) {
      cout << "Bucket " << i << "-->";
      Node<T>* temp = table[i];
      while (temp) {
        cout << temp->key << "-->";
        temp = temp->next;
      }
      cout << endl;
    }
  }
};

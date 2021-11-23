#pragma once
#include <bits/stdc++.h>
using namespace std;
class Node {
  int data;

 public:
  Node *next;

 public:
  Node(int d) : data(d), next(NULL) {}
  void setNext(Node *x) { next = x; }
  Node *getNext() { return next; }
  int getData() { return data; }

  ~Node() {
    if (next != NULL) {
      delete next;
    }
    cout << "deleting Node with data: " << data << endl;
  }
};

class List {
  Node *front;
  Node *back;

  void reverseHelper(Node *c) {
    Node *p = NULL;
    Node *next = NULL;
    if (c->next == NULL) return;
    while (c != NULL) {
      next = c->next;
      c->next = p;
      p = c;
      c = next;
    }
    front = p;
  }

 public:
  List() : front(NULL), back(NULL) {}
  Node *getFront() { return front; }
  Node *getBack() { return back; }
  void push_front(int data) {
    Node *x = new Node(data);
    if (front == NULL) {
      front = back = x;
    } else {
      x->setNext(front);
      front = x;
    }
  }
  void push_back(int data) {
    Node *x = new Node(data);
    if (front == NULL) {
      front = back = x;
    } else {
      back->setNext(x);
      back = x;
    }
  }
  void insert(int data, int pos) {
    if (pos == 0) push_front(data);
    Node *temp = front;
    for (int i = 0; i < pos - 1; i++) {
      temp = temp->getNext();
    }
    Node *x = new Node(data);
    x->setNext(temp->getNext());
    temp->setNext(x);
  }
  void reverse() { reverseHelper(front); }

  void remove(int data) {  // learn how to do it recursively
    Node *temp = front;
    Node *prev = NULL;

    while (temp && temp->getData() == data) {
      Node *temp = front;
      front = front->next;

      temp->next = NULL;
      delete temp;
      return;
    }
    while (temp && temp->getData() != data) {
      prev = temp;
      temp = temp->next;
    }
    if (temp == NULL) return;

    prev->next = temp->next;
    temp->next = NULL;  // to delete just this node
    delete temp;
  }

  ~List() {
    if (front != NULL) {
      delete front;
      front = NULL;  // I don't think this is really required
    }
  }
};
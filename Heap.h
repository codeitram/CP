#include <bits/stdc++.h>
using namespace std;

// we can use a var to switch comparision by making compr() minHeap to maxHeap
class minHeap {
  vector<int> v;

  void heapify(int idx) {
    // simpler way would to be find index of minelement and continue when it is
    // not same as idx
    int ch1 = 2 * idx;
    int ch2 = 2 * idx + 1;
    int temp = ch1;
    if (idx >= v.size()) return;
    if (ch1 < v.size() and v[ch1] < v[idx]) {
      swap(v[ch1], v[idx]);
      temp = ch1;
    }
    if (ch2 < v.size() and v[ch2] < v[idx]) {
      swap(v[ch2], v[idx]);
      temp = ch2;
    }
    heapify(temp);
  }

 public:
  minHeap(int default_size = 10) {
    v.reserve(default_size + 1);
    v.push_back(-1);
  }

  void push(int data) {
    v.push_back(data);
    int idx = v.size() - 1;
    int parent = idx / 2;
    while (idx >= 1 and v[idx] < v[parent]) {
      swap(v[idx], v[parent]);
      parent /= 2;
      idx /= 2;
    }
  }
  int top() { return v[1]; }

  void pop() {
    int idx = v.size() - 1;
    swap(v[1], v[idx]);
    v.pop_back();
    heapify(1);
  }
  bool empty() { return v.size() == 1; }
};
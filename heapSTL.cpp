#include <bits/stdc++.h>
using namespace std;

class Compare {
 public:
  bool operator()(int a, int b) { return a > b; }
};

int main() {
  priority_queue<int, vector<int>, Compare>
      heap;  // yes this is way to declare Maxheap
  // priority_queue<int> heap;  // this is way to create Maxheap
  int marks[] = {90, 80, 12, 13, 15, 56, 94};

  for (auto x : marks) {
    heap.push(x);
  }
  while (!heap.empty()) {
    cout << heap.top() << endl;
    heap.pop();
  }
}
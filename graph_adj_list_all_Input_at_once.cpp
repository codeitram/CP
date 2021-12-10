#include <bits/stdc++.h>
using namespace std;

class Node {
 public:
  string s;
  list<string> l;

 public:
  Node(string s) { this->s = s; }
};

class Graph {
  unordered_map<string, Node *> hash;

 public:
  Graph(vector<string> s) {
    for (auto x : s) {
      hash[x] = new Node(x);
    }
  }
  void addEdge(string s1, string s2, bool undir = false) {
    hash[s1]->l.push_back(s2);
    if (undir) hash[s2]->l.push_back(s1);
  }

  void printAdjList() {
    for (auto cityPair : hash) {
      auto city = cityPair.first;  // todo: this is some work
      Node *node = cityPair.second;
      cout << city << "-->";
      for (auto nbr : node->l) {
        cout << nbr << ",";
      }
      cout << endl;
    }
  }
};

int main() {
  vector<string> cities = {"Delhi", "London", "Paris", "New York"};
  Graph g(cities);

  g.addEdge("Delhi", "London");
  g.addEdge("New York", "London");
  g.addEdge("Delhi", "Paris");
  g.addEdge("Paris", "New York");

  g.printAdjList();

  return 0;
}
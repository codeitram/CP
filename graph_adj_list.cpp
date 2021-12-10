#include <bits/stdc++.h>
using namespace std;

class Graph {
 private:
  list<int>* s;
  int vertices;

 public:
  Graph(int v) {
    vertices = v;
    s = new list<int>[vertices];
  }

  void addEdge(int i, int j, bool undir = true) {
    s[i].push_back(j);
    if (undir) s[j].push_back(i);
  }
  void printEdge() {
    for (int i = 0; i < vertices; i++) {
      cout << "list" << ' ' << i << "-->";
      for (auto i : s[i]) cout << i << " ";
      cout << endl;
    }
  }

  void bfs(int source) {
    queue<int> q;
    bool* visited = new bool[vertices]{0};
    q.push(source);
    visited[source] = true;
    while (!q.empty()) {
      int f = q.front();
      q.pop();
      cout << f << endl;
      for (auto nbr : s[f]) {
        if (!visited[nbr]) {
          q.push(nbr);
          visited[nbr] = true;
        }
      }
    }
  }

 private:
  void dfsHelper(int source, bool* visited) {
    visited[source] = true;
    cout << source << ' ';
    for (auto a : s[source]) {
      if (!visited[a]) dfsHelper(a, visited);
    }
    return;
  }

 public:
  void dfs(int source) {
    bool* visited = new bool[vertices]{false};
    dfsHelper(source, visited);
  }

  void toplogicalSort() {
    vector<int> indegree(vertices, 0);
    // couting indegree
    for (int i = 0; i < vertices; i++) {
      for (auto x : s[i]) indegree[i]++;
    }

    queue<int> q;
    for (int i = 0; i < vertices; i++) {
      if (indegree[i] == 0) q.push(i);
    }

    while (!q.empty()) {
      cout << q.front() << ' ';
      q.pop();
      for (auto x : s[q.front()]) {
        indegree[x]--;
        if (indegree[x] == 0) q.push(x);
      }
    }
  }
};

int main() {
  Graph g(6);
  g.addEdge(0, 1);
  g.addEdge(0, 4);
  g.addEdge(2, 1);
  g.addEdge(3, 4);
  g.addEdge(4, 5);
  g.addEdge(2, 3);
  g.addEdge(3, 5);
  g.printEdge();
  g.dfs(1);
  // for bfs testing

  // Graph g(7);
  // g.addEdge(0, 1);
  // g.addEdge(1, 2);
  // g.addEdge(2, 3);
  // g.addEdge(3, 5);
  // g.addEdge(5, 6);
  // g.addEdge(4, 5);
  // g.addEdge(0, 4);
  // g.addEdge(3, 4);
  // g.bfs(1);
  // return 0;
}
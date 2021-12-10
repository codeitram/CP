#include <bits/stdc++.h>
using namespace std;

class Graph {
  int noOfVertices;
  list<pair<int, int>> *l;

 public:
  Graph(int v) {
    noOfVertices = v;
    l = new list<pair<int, int>>[v];
  }

  void addEdge(int u, int v, int wt, bool undir = true) {
    l[u].push_back({v, wt});
    if (undir) {
      l[v].push_back({v, wt});
    }
  }

  int Dijkstra(int source, int dest) {
    vector<int> distance(noOfVertices, INT_MAX);
    set<pair<int, int>> currentDistance;

    distance[source] = 0;
    currentDistance.insert({source, distance[source]});

    while (!currentDistance.empty()) {
      auto i = currentDistance.begin();
      int vert = i->first;
      int dist = i->second;
      currentDistance.erase({vert, dist});
      for (auto x : l[vert]) {
        int nbrNode = x.first;
        int nbrCost = x.second;

        if (dist + nbrCost < distance[nbrNode]) {
          auto f = currentDistance.find({nbrNode, distance[nbrNode]});
          if (f != currentDistance.end()) currentDistance.erase(f);
          distance[nbrNode] = dist + nbrCost;
          currentDistance.insert({nbrNode, distance[nbrNode]});
        }
      }
    }
    for (int i = 0; i < noOfVertices; i++) {
      cout << "Node i " << i << " Dist " << distance[i] << endl;
    }
    return distance[dest];
  }
};

int main() {
  Graph g(5);
  g.addEdge(0, 1, 1);
  g.addEdge(1, 2, 1);
  g.addEdge(0, 2, 4);
  g.addEdge(0, 3, 7);
  g.addEdge(3, 2, 2);
  g.addEdge(3, 4, 3);

  cout << g.Dijkstra(0, 4) << endl;
}
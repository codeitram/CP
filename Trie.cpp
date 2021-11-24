#include <bits/stdc++.h>

#include "Tries.h"
using namespace std;

int main() {
  string words[] = {"hello", "he", "apple", "aple", "news"};

  Trie h;
  for (auto a : words) {
    h.insert(a);
  }
  h.remove("hello");
  string key;
  cin >> key;
  cout << h.search(key);
}
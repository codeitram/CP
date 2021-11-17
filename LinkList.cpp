#include "linkList.h"

#include <bits/stdc++.h>
using namespace std;

int main() {
  List l1;
  l1.push_back(2);
  l1.push_back(3);
  l1.push_back(4);
  l1.push_back(5);
  // l1.insert(10, 3);
  l1.reverse();

  auto itr = l1.getFront();
  while (itr != NULL) {
    cout << itr->getData() << "-->";
    itr = itr->getNext();
  }
}
#include "hashTable.h"

#include <bits/stdc++.h>

int main() {
  hashTable<int> h;
  h.insert("Mango", 100);
  h.insert("Apple", 120);
  h.insert("Banana", 140);
  h.insert("Orange", 200);
  h.insert("Kiwi", 210);
  h.insert("Papaya", 220);
  h.insert("Litchi", 300);
  h["Water Chestnut"] = 500;
  h["Water Chestnut"] += 300;
  cout << "Cost of water Chestnut is :" << h["Water Chestnut"] << '\n';
  h.remove("Kiwi");
  string fruitName = "Water Chestnut";
  if (h.isPresent(fruitName)) {
    int x = h.search2(fruitName);
    cout << "Price is: " << x << endl;

  } else {
    cout << "Not found" << endl;
  }

  h.print();
}
// revise let's redo once
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  int count = 0;
  for (int i = 0; i < n; i++) {
    int counti = 0;
    for (int j = 0; j < 3; j++) {
      int temp;
      cin >> temp;
      counti += temp;
    }
    if (counti >= 2) count++;
  }
  cout << count;
}
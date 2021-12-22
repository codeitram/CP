#include <bits/stdc++.h>
using namespace std;

int main() {
  int x, y;
  cin >> x >> y;
  int test = x + 1;
  bool print = false;
  while (test <= y) {
    bool flag = true;
    for (int i = 2; i < test; i++) {
      if (test % i == 0) {
        flag = false;
        break;
      }
    }
    if (flag) {
      if (test == y) {
        cout << "YES";
        print = true;
      } else {
        cout << "NO";
        print = true;
      }
      flag = false;
      break;
    }
    test++;
  }
  if (!print) cout << "NO";
}
#include <bits/stdc++.h>
using namespace std;

int main() {
  int x;
  cin >> x;
  while (true) {
    x++;
    stringstream ss;
    ss << x;
    char no[4];
    for (int i = 0; i < 4; i++) {
      ss >> no[i];
    }
    int flag = false;
    for (int i = 0; i < 4; i++) {
      for (int j = i + 1; j < 4; j++) {
        if (no[i] == no[j]) flag = true;
        if (flag) break;
      }
      if (flag == true) break;
    }
    if (flag == false) {
      cout << x;
      break;
    }
  }
}
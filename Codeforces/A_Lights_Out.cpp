#include <bits/stdc++.h>
using namespace std;

int main() {
  int a[3][3];
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> a[i][j];
    }
  }

  int res[3][3]{0};
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      int total = 0;
      total += a[i][j];
      if (i - 1 >= 0) total += a[i - 1][j];
      if (j - 1 >= 0) total += a[i][j - 1];
      if (i + 1 < 3) total += a[i + 1][j];
      if (j + 1 < 3) total += a[i][j + 1];
      // cout << "total at" << i << ' ' << j << total << endl;
      if (total & 1)
        res[i][j] = 0;
      else
        res[i][j] = 1;
    }
  }

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cout << res[i][j];
    }
    cout << endl;
  }
}
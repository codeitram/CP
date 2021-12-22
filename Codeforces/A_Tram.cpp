#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  int maxc = INT_MIN;
  int total = 0;
  while (n--) {
    int x, y;
    cin >> x >> y;
    total = total - x + y;
    maxc = max(total, maxc);
  }
  cout << maxc;
}
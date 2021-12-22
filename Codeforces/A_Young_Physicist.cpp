#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int x, y, z;
  long long xt = 0, yt = 0, zt = 0;
  while (N--) {
    cin >> x >> y >> z;
    xt += x;
    yt += y;
    zt += z;
  }
  if (xt == 0 && yt == 0 && zt == 0)
    cout << "YES\n";
  else
    cout << "NO\n";
}
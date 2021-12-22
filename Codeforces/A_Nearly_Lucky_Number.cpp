#include <bits/stdc++.h>
using namespace std;

int main() {
  long long x;
  cin >> x;

  int count{0};
  while (x) {
    int d = x % 10;
    if (d == 7 || d == 4) count++;
    x /= 10;
  }
  bool flag = true;
  if (count == 0) flag = false;
  while (count) {
    int d = count % 10;
    if (!(d == 7 || d == 4)) {
      flag = false;
      break;
    }
    count /= 10;
  }
  if (flag)
    cout << "YES";
  else
    cout << "NO";
}
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  int right = 0;
  int left = 0;
  for (int i = 0; i < n; i++) {
    int l, r;
    cin >> l >> r;
    right += r;
    left += l;
  }
  cout << min(left, n - left) + min(right, n - right);
}

#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k, l, c, d, p, nl, np;
  cin >> n >> k >> l >> c >> d >> p >> nl >> np;
  int drink_quan = k * l;
  int slices = c * d;
  cout << min(min(drink_quan / nl, p / np), slices) / n;
}
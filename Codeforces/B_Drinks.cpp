#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  int n_C = n;
  int res = 0;
  while (n--) {
    int temp;
    cin >> temp;
    res += temp;
  }
  cout.precision(numeric_limits<double>::digits10);  // revise
  cout << fixed << (double)res / (n_C);
}
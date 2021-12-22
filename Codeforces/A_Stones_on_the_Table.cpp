#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  string inp;
  cin >> inp;
  char c = inp[0];
  int count{0};
  for (int i = 1; i < n; i++) {
    if (inp[i] == c) count++;
    c = inp[i];
  }
  cout << count;
}
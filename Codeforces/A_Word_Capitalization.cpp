#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  char c = s[0];
  if (c > 'Z') c = c - ('a' - 'A');
  s[0] = c;
  cout << s;
}
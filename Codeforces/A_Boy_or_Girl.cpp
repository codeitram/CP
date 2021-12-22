#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  int a[26]{0};
  for (auto x : s) {
    a[x - 'a'] = 1;
  }
  int count = 0;
  for (int i = 0; i < 26; i++) {
    if (a[i] == 1) count++;
  }
  if (count & 1)
    cout << "IGNORE HIM!";
  else
    cout << "CHAT WITH HER!";
}
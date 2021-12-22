#include <bits/stdc++.h>
using namespace std;

int main() {
  string s1, s2, s3;
  cin >> s1 >> s2 >> s3;
  int a[26]{0};
  if (s1.length() + s2.length() != s3.length())
    cout << "NO";
  else {
    for (auto x : s3) {
      a[x - 'A']++;
    }
    for (auto x : s1) {
      a[x - 'A']--;
    }
    for (auto x : s2) {
      a[x - 'A']--;
    }
    for (int i = 0; i < 26; i++) {
      if (a[i] != 0) {
        cout << "NO";
        return 0;
      }
    }
    cout << "YES";
  }
}
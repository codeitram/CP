#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  int count = 0;
  int num = 0;
  stringstream ss;
  for (int i = 0; i < s.size();) {
    if (s[i] == '.') {
      ss << 0;
      i++;
    } else if (s[i] == '-') {
      i++;
      if (s[i] == '.') {
        ss << 1;
        i++;
      } else if (s[i] == '-') {
        ss << 2;
        i++;
      }
    }
  }

  cout << ss.str();
}
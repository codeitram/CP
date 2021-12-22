#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  while (n--) {
    string s;
    cin >> s;
    if (s.length() <= 10)
      cout << s << endl;
    else {
      string temp;
      temp = s[0];
      temp = temp + to_string(s.length() - 2);
      temp = temp + s[s.length() - 1];
      cout << temp << endl;
    }
  }
}
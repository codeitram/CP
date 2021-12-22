#include <bits/stdc++.h>
using namespace std;

int main() {
  string s1, s2;
  cin >> s1 >> s2;
  int length = s1.size();

  stringstream ss;
  for (int i = 0; i < length; i++) {
    int a = s1[i] - '0';
    int b = s2[i] - '0';
    // cout << "a :" << a << "b :" << b << endl;
    ss << (a ^ b);
  }
  cout << ss.str();
}
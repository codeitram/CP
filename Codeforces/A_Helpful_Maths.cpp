
#include <bits/stdc++.h>
using namespace std;

int main() {
  int a[3]{0};
  string s;
  cin >> s;
  // cout << s;
  int temp;
  int len = s.size();
  len -= len / 2;  // revise
  stringstream ss(s);
  while (len--) {
    ss >> temp;
    a[temp - 1]++;
    ss.ignore();  // in the last run there is nothing to ignore on stream so
                  // don't worry abou it
  }

  stringstream st;
  for (int i = 0; i < 3; i++) {
    while (a[i]) {
      st << i + 1 << '+';
      a[i]--;
    }
  }
  s = st.str();
  s = s.substr(0, s.length() - 1);
  cout << s;
}
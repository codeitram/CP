#include <bits/stdc++.h>
using namespace std;

int main() {
  string input;
  cin >> input;
  string upper(input), lower(input);
  int con = 'a' - 'A';
  int up = 0, lo = 0;
  for (int i = 0; i < input.size(); i++) {
    if (input[i] - 'a' < 0) {
      lower[i] = lower[i] + con;
      up++;
    } else {
      upper[i] = upper[i] - con;
      lo++;
    }
  }
  if (up > lo)
    cout << upper;
  else
    cout << lower;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
  int i = -1, j = -1;
  int count = 0;
  while (true) {
    int temp;
    cin >> temp;
    j++;
    j = j % 5;
    if (j == 0) i++;
    if (temp == 1) break;
  }
  cout << abs(i - 2) + abs(j - 2);
}
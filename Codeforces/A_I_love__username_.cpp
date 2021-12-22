#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  int best, worst;
  cin >> best;
  worst = best;
  int count = 0;
  n--;
  while (n--) {
    int temp;
    cin >> temp;
    if (temp > best) {
      count++;
      best = temp;
    } else if (temp < worst) {
      count++;
      worst = temp;
    }
  }
  cout << count;
}
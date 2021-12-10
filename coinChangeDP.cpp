#include <bits/stdc++.h>
using namespace std;

int minNoOfCoinForChange(int amt, vector<int> denoms) {  // bottom-up
  vector<int> minRequired(amt + 1, INT_MAX);
  minRequired[0] = 0;
  for (int i = 1; i <= amt; i++) {
    for (auto x : denoms) {
      // minrequired[i-x]!= int_max is corner case, because if you add 1 it will
      // be -ve and hence least values
      if (i >= x and minRequired[i - x] != INT_MAX) {
        minRequired[i] = min(minRequired[i], minRequired[i - x] + 1);
      }
    }
  }
  return minRequired[amt] == INT_MAX ? -1 : minRequired[amt];
}

int minNoOfCoin(int amt, vector<int> denoms, vector<int> minCost) {  // top-down
  if (amt == 0) return 0;

  if (minCost[amt] != INT_MAX)
    return minCost[amt];
  else {
    for (auto x : denoms) {
      if (amt >= x) {
        int temp = minNoOfCoin(amt - x, denoms, minCost);
        if (temp != INT_MAX) {
          minCost[amt] = min(minCost[amt], temp + 1);
        }
      }
    }
  }
  return minCost[amt];
}

int main() {
  vector<int> denoms = {1, 5, 7, 10};
  int amt = 16;
  cout << minNoOfCoinForChange(amt, denoms) << endl;
  vector<int> minCost(amt + 1, INT_MAX);
  cout << minNoOfCoin(amt, denoms, minCost);
}
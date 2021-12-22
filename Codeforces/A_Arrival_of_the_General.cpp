#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> pos;
  while (n--) {
    int temp;
    cin >> temp;
    pos.push_back(temp);
  }
  int maxElement = max_element(pos.begin(), pos.end()) - pos.begin();
  int minElement = min_element(pos.rbegin(), pos.rend()) - pos.rbegin();
  // minElement = pos.size() - 1 - minElement;
  int count = 0;
  // cout << "MIN: " << minElement << "max: " << maxElement;
  if (pos.size() - 1 - minElement < maxElement) count = -1;
  count = count + maxElement + minElement;
  cout << count;
}
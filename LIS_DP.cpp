#include <bits/stdc++.h>
using namespace std;

int lis(vector<int> arr) {
  // int max = INT_MIN;
  vector<int> length(arr.size(), 0);
  length[0] = 1;
  int maxLength = 1;
  for (int i = 1; i < arr.size(); i++) {
    for (int j = 0; j < i; j++) {
      if (arr[i] > arr[j]) {
        length[i] = max(length[i], length[j] + 1);
      }
      maxLength = max(maxLength, length[i]);
    }
  }
  return maxLength;
}

int main() {
  vector<int> arr{50, 4, 10, 8, 30, 100};
  cout << lis(arr) << endl;
}
// revise and find out why time limit is exceeding
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  int n_C;
  cin >> n;
  n_C = n;
  vector<int> v(100001, 0);
  int idx = 1;
  while (n--) {
    int temp;
    cin >> temp;
    v[temp] = idx;
    idx++;
  }
  cin >> n;
  long long count1 = 0, count2 = 0;
  long count = 0;

  while (n--) {
    int temp;
    cin >> temp;
    // int count = 0;
    // for (auto x : v) {
    //   count++;
    //   if (x == temp) {
    //     break;
    //   }
    // }
    count = v[temp];
    count1 += count;
    count2 += n_C - count + 1;
    count = 0;
  }
  cout << count1 << ' ' << count2;
}
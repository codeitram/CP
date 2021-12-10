#include <bits/stdc++.h>
using namespace std;

// Todo: fix this one
int knapsack(int wts[], int price[], int N, int weight, int *store) {
  int form = 4 * (N - 1) + weight - 1;
  if (N == 0 || weight == 0) return 0;

  if (store[form] != INT_MAX)
    return store[form];
  else {
    int inc = 0, exc = 0;  // I have not intialized it once, and in next line if
                           // condition is not executed for few case in this
                           // cases I have faced werid bugs
    if (wts[N - 1] <= weight)
      inc = price[N - 1] +
            knapsack(wts, price, N - 1, weight - wts[N - 1], store);
    exc = knapsack(wts, price, N - 1, weight, store);
    store[form] = max(inc, exc);
  }
  return store[form];
}

int knapsackBottom(int wts[], int price[], int N, int weight) {
  vector<vector<int>> dp(N + 1, vector<int>(weight + 1, 0));
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= weight; j++) {
      int inc = 0, exc = 0;
      if (wts[i - 1] <= wts[j - 1]) {
        inc = price[i - 1] + dp[i - 1][weight - wts[j - 1]];
      }
      if (i - 2 >= 0) exc = dp[i - 2][wts[j - 1]];
      dp[i][j] = max(inc, exc);
    }
  }
  return dp[N][weight];
}

int main() {
  int wts[] = {2, 7, 3, 4};
  int price[] = {5, 20, 20, 10};
  int N = 4;
  int weight = 10;
  int x[N][N];
  // setting value to INTmax of x
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) x[i][j] = INT_MAX;
  }
  // int res = knapsackB(wts, price, N, weight, (int *)x);
  int res = knapsackBottom(wts, price, N, weight);
  cout << "VALUE: " << res;
}
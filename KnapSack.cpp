#include <bits/stdc++.h>
using namespace std;

int knapsackBottom(int wts[], int price[], int n, int w) {
  vector<vector<int>> dp(n + 1, vector<int>(w + 1));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= w; j++) {
      int inc = 0, exc = 0;
      if (wts[i - 1] <= j) inc = price[i - 1] + dp[i - 1][j - wts[i - 1]];
      exc = dp[i - 1][j];
      dp[i][j] = max(inc, exc);
    }
  }
  return dp[n][w];
}

int knapsackTop(int wts[], int price[], int n, int w, vector<vector<int>> &dp) {
  if (n == 0 or w == 0) return 0;
  if (dp[n][w] != INT_MAX)
    return dp[n][w];
  else {
    int inc = 0, exc = 0;
    if (wts[n - 1] <= w)
      inc = price[n - 1] + knapsackTop(wts, price, n - 1, w - wts[n - 1], dp);
    exc = knapsackTop(wts, price, n - 1, w, dp);
    dp[n][w] = max(inc, exc);
  }
  return dp[n][w];
}

int main() {
  int wts[] = {2, 7, 3, 4};
  int price[] = {5, 20, 20, 10};
  int N = 4;
  int weight = 10;

  vector<vector<int>> dp(N + 1, vector<int>(weight + 1, INT_MAX));

  int res1 = knapsackTop(wts, price, N, weight, dp);
  int res = knapsackBottom(wts, price, N, weight);

  cout << "VALUE: " << res;
  cout << endl << "Value: " << res1;
}
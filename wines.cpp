#include <bits/stdc++.h>
using namespace std;

int wines(int dp[][10], int a[], int L, int E, int y) {
  if (L > E) return 0;
  if (dp[L][E] != 0) return dp[L][E];

  int left = y * a[L] + wines(dp, a, L + 1, E, y + 1);
  int right = y * a[E] + wines(dp, a, L, E - 1, y + 1);

  return dp[L][E] = max(left, right);
}
int winesBottom(int a[], int n) {
  vector<vector<int>> dp(n, vector<int>(n, 0));
  for (int i = n - 1; i >= 0; i--) {
    for (int j = 0; j < n; j++) {
      int y = n - (j - i);
      if (i == j)
        dp[i][j] = y * a[i];
      else if (i < j) {
        int pick_left = a[i] * y + dp[i + 1][j];
        int pick_right = a[j] * y + dp[i][j - 1];
        dp[i][j] = max(pick_left, pick_right);
      }
    }
  }
  return dp[0][n - 1];
}
int main() {
  int a[] = {2, 3, 5, 1, 4};
  int n = 5;
  int dp[10][10] = {0};
  cout << wines(dp, a, 0, n - 1, 1) << endl;
  cout << "Bottom up: " << winesBottom(a, n);
}
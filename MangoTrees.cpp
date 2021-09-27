// so # are mango trees here, and you are asked to divide this in four partition on
// quadarant and you will min in it, so try to get max# by dividing it
#include <bits/stdc++.h>
using namespace std;

int mangoTrees(int a[][6], int n, int m)
{
    int twoDPrefixSum[100][100];

    twoDPrefixSum[0][0] = a[0][0] == '#' ? 1 : 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int add = 0;
            if (a[i][j] == '#')
                add = 1;

            if (i > 0 and j > 0)
            {
                twoDPrefixSum[i][j] = twoDPrefixSum[i - 1][j] + twoDPrefixSum[i][j - 1] - twoDPrefixSum[i - 1][j - 1];

                twoDPrefixSum[i][j] += add;
            }

            else if (i == 0 and j > 0)
            {
                twoDPrefixSum[i][j] = twoDPrefixSum[i][j - 1] + add;
            }
            else if (j == 0 and i > 0)
                twoDPrefixSum[i][j] = add + twoDPrefixSum[i - 1][j];

            add = 0;
        }
    }

    int maximum = INT_MIN;
    for (int i = 1; i < n; i++)
    {
        int minimum;
        for (int j = 1; j < m; j++)
        {
            int s1, s2, s3, s4;
            s1 = twoDPrefixSum[i - 1][j - 1];
            s2 = twoDPrefixSum[i - 1][m - 1] - s1;
            s3 = twoDPrefixSum[n - 1][j - 1] - s1;
            s4 = twoDPrefixSum[n - 1][m - 1] - s1 - s2 - s3;
            minimum = min(min(min(s1, s2), s3), s4);
            maximum = max(maximum, minimum); // I put this in next loop and i was stuck        }
        }
    }
    return maximum;
}

int main()
{
    int a[][6] = {
                  {'-', '#', '#', '-', '-', '-'},
                  {'#', '-', '-', '#', '#', '-'},
                  {'-', '#', '-', '-', '-', '-'},
                  {'-', '#', '#', '-', '-', '#'},
                  {'#', '-', '-', '#', '#', '-'},
                  {'-', '#', '-', '-', '-', '-'}
                  };
    int n = 6, m = 6;
    cout << mangoTrees(a, n, m);
}
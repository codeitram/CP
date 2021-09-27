#include <bits/stdc++.h>
using namespace std;

void printSpiral(int a[][4], int n, int m)
{
    int sr = 0, er = n - 1, sc = 0, ec = m - 1;
    while (sr <= er and sc <= ec)
    {
        for (int j = sc; j <= ec; j++)
            cout << a[sr][j] << ' ';
        for (int i = sr + 1; i <= er - 1; i++)
            cout << a[i][ec] << ' ';

        for (int j = ec; j >= sc; j--)
        {
            if (sr == er)
                break;
            cout << a[er][j] << ' ';
        }
        for (int i = er - 1; i >= sr + 1; i--)
        {
            if (ec == sc)
                break;
            cout << a[i][sc] << ' ';
        }
        sr += 1;
        er -= 1;
        sc += 1;
        ec -= 1;
    }
}
int main()
{
    int a[4][4] = {{1, 2, 3, 4}, {12, 13, 14, 5}, {11, 16, 15, 6}, {10, 9, 8, 7}};
    int n = 4, m = 4;
    printSpiral(a, n, m);
}
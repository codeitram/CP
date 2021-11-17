#include <bits/stdc++.h>
using namespace std;

void printMatrix(int board[][20], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << board[i][j] << ' ';
        }
        cout << endl;
    }
}
bool canPlace(int board[][20], int i, int j, int n)
{
    for (int row = 0; row <= i; row++)
    {
        if (board[row][j] == 1)
            return false;
    }
    int row = i, col = j;
    while (row >= 0 and col >= 0)
    {
        if (board[row][col] == 1)
            return false;
        row--;
        col--;
    }
    row = i;
    col = j;
    while (row >= 0 and col < n)
    {
        if (board[row][col] == 1)
            return false;
        row--;
        col++;
    }
    return true;
}

int solveNqueen(int board[][20], int n, int i)
{
    if (i == n)
    {
        printMatrix(board, n);
        cout << endl << endl;
        return 1;
    }
    int ways = 0;
    for (int j = 0; j < n; j++)
    {
        if (canPlace(board, i, j, n))
        {
            board[i][j] = 1;
            ways += solveNqueen(board, n, i + 1);
            board[i][j] = 0;
        }
    }
    return ways;
}
int main()
{
    int board[20][20] = {0};
    int n;
    cin >> n;
    int res = solveNqueen(board, n, 0);
    cout << res;
}

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

bool solveNqueen(int board[][20], int n, int i)
{
    // base case
    if (i == n)
    {
        printMatrix(board, n);
        return true;
    }
    // recursive case
    for (int j = 0; j < n; j++)
    {
        if (canPlace(board, i, j, n))
        {
            board[i][j] = 1;
            bool res = true;
            res = solveNqueen(board, n, i + 1);
            if (res)
                return true;
            if (!res)
                board[i][j] = 0;
        }
    }
    return false;
}
int main()
{
    int board[20][20] = {0};
    int n;
    cin >> n;
    bool res = solveNqueen(board, n, 0);
    if (!res)
        cout << "NO possible configuration exists";
}

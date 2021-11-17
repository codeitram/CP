#include <bits/stdc++.h>

using namespace std;

bool canPlace(int mat[][9], int i, int j, int no)
{
    for (int a = 0; a < 9; a++)
    {
        if (mat[a][j] == no or mat[i][a] == no)
            return false;
    }
    int sx, sy;
    sx = i / 3 * 3;
    sy = j / 3 * 3;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (mat[i + sx][j + sy] == no)
                return false;
        }
    }
    return true;
}

bool solveSudoku(int mat[][9], int i, int j, int n)
{
    // base case
    if (i == n)
    {
        for (int a = 0; a < n; a++)
        {
            for (int b = 0; b < n; b++)
            {
                cout << mat[a][b] << ' ';
            }
            cout << endl;
        }
        return true;
    }

    if (j == n)
        return solveSudoku(mat, i + 1, 0, n);
    if (mat[i][j] != 0)
        return solveSudoku(mat, i, j + 1, n);

    for (int a = 1; a <= n; a++)
    {
        if (canPlace(mat, i, j, a))
        {
            mat[i][j] = a;
            bool res = solveSudoku(mat, i, j + 1, n);
            if (res)
                return true;
        }
    }
    mat[i][j] = 0;
    return false;
}
int main()
{
    int n = 9;
    int mat[9][9] = {{5, 3, 0, 0, 7, 0, 0, 0, 0}, {6, 0, 0, 1, 9, 5, 0, 0, 0}, {0, 9, 8, 0, 0, 0, 0, 6, 0},
                     {8, 0, 0, 0, 6, 0, 0, 0, 3}, {4, 0, 0, 8, 0, 3, 0, 0, 1}, {7, 0, 0, 0, 2, 0, 0, 0, 6},
                     {0, 6, 0, 0, 0, 0, 2, 8, 0}, {0, 0, 0, 4, 1, 9, 0, 0, 5}, {0, 0, 0, 0, 8, 0, 0, 7, 9}};

    if (!solveSudoku(mat, 0, 0, n))
    {
        cout << "No solution exists!";
    }
}
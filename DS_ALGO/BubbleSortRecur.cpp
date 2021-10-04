#include <bits/stdc++.h>
using namespace std;

void bubbleSort(int *a, int n, int j)
{
    if (n == 1 or n == 0)
        return;
    // for (int i = 0; i < n - 1; i++)
    // {
    //     if (a[i] > a[i + 1])
    //         swap(a[i], a[i + 1]);
    // }
    if (j == n - 1)
    {
        bubbleSort(a, n - 1, 0);
        return; // why this return is important ?
    }
    if (a[j] > a[j + 1]) // this condition is just for swap not to check whether to make next call or not
    {
        swap(a[j], a[j + 1]);
    }
    bubbleSort(a, n, j + 1);
    
}
int main()
{
    int a[] = {-2, 3, 4, -1, 5, -12, 6, 1, 3};
    int n = sizeof(a) / sizeof(int);
    bubbleSort(a, n, 0);
    for (int i = 0; i < n; i++)
        cout << a[i] << ' ';
}

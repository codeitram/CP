#include <bits/stdc++.h>
using namespace std;

bool isSorted(int *a, int n)
{
    if (n == 0 || n == 1)
        return true;
    return a[0] <= a[1] && isSorted(a + 1, n - 1);
}
int main()
{
    int a[] = {1, 2, 2, 3, 4, 5, 4};
    int n = sizeof(a) / sizeof(int);

    cout << isSorted(a, n);
}
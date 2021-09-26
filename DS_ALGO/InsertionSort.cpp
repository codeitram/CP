#include <bits/stdc++.h>
using namespace std;

void insertionSort(int *a, int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = i;
        for (int j = i - 1; j >= 0; j--)
        {
            if (a[key] < a[j])
                swap(a[key--], a[j]);
            else
                break;
        }
    }
}

int main()
{
    int a[] = {-2, 3, 4, -1, 5, -12, 6, 1, 3};
    int n = sizeof(a) / sizeof(int);

    insertionSort(a, n);
    for (int i = 0; i < n; i++)
        cout << a[i] << ' ';
}
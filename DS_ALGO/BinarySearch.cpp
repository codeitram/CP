#include <bits/stdc++.h>
using namespace std;

int binarySearch(int *a, int n, int key)
{
    int i = 0, j = n - 1;
    while (i <= j)
    {
        int mid = (i + j) / 2;
        if (a[mid] == key)
            return mid;
        else if (a[mid] > key)
            j = mid - 1;
        else
            i = mid + 1;
    }
    return -1;
}

int binarySearchR(int *a, int i, int j, int key)
{
    if (i > j)
        return -1;
    int mid = (i + j) / 2;
    if (a[mid] == key)
        return mid;
    return a[mid] > key ? binarySearchR(a, i, mid - 1, key) : binarySearchR(a, mid + 1, j, key);
}

int main()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(a) / sizeof(int);
    cout << binarySearchR(a, 0, n, 384);
}
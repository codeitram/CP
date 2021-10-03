#include <bits/stdc++.h>
using namespace std;

int firstOccurence(int *a, int n, int k)
{
    if (n == 0)
        return -1;
    if (a[0] == k)
        return 0;
    int subIndex = firstOccurence(a + 1, n - 1, k);
    return subIndex != -1 ? 1 + subIndex : -1; // this check of subIndex is not -1 is what I missed
}
int lastOccurence(int *a, int n, int k)
{
    if (n == 0)
        return -1;
    int subIndex = firstOccurence(a + 1, n - 1, k);
    if (subIndex == -1)
    {
        if (a[0] == k)
            return 0;
        else
            return -1;
    }
    else
    {
        return subIndex + 1;
    }
}
int main()
{
    int a[] = {10, 2, 3, 5, 7, 8, 10};
    int n = sizeof(a) / sizeof(int);
    cout << firstOccurence(a, n, 10);
    cout<<lastOccurence(a,n,10);
}
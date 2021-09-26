#include <bits/stdc++.h>
using namespace std;

int maxSubarray(int *a, int n)
{
    int prefixSum[100]; // use constand in msvc compiler in gcc can use variable n also
    prefixSum[0] = a[0];
    for (int i = 1; i < n; i++) // Prefix Sum
    {
        prefixSum[i] = prefixSum[i - 1] + a[i];
    }
    int current = 0, largest = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            current = i > 0 ? prefixSum[j] - prefixSum[i - 1] : prefixSum[j];
            largest = max(current, largest);
        }
    }
    return largest;
}

int main()
{
    int a[] = {-2, 3, 4, -1, 5, -12, 6, 1, 3};
    int n = sizeof(a) / sizeof(int);
    cout << maxSubarray(a, n);
}
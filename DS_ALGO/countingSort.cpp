#include <bits/stdc++.h>
using namespace std;

// Yes I made this general counting sort, so no can be negative too
// T.C = O(linear+range) SC = O(range)
void countingSort(int *arr, int n)
{
    int largest = INT_MIN;
    int smallest = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        largest = max(largest, arr[i]);
        smallest = min(smallest, arr[i]);
    }
    int totalSize = largest - smallest + 1;
    int *freq = new int[totalSize];
    memset(freq, 0, totalSize * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        freq[arr[i] - smallest]++;
    }

    int k = 0;
    for (int i = 0; i < totalSize; i++)
    {

        while (freq[i]--)
        {
            arr[k] = smallest + i;
            k++;
        }
    }
}
int main()
{
    int arr[] = {88, 97, 10, 12, 15, 1, 5, 6, 12, -5, 8, -5, -8};
    int n = sizeof(arr) / sizeof(int);
    countingSort(arr, n);
    for (auto i : arr)
        cout << i << ' ';
}
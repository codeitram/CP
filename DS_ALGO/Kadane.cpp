#include <bits/stdc++.h>
using namespace std;

int kadane(int *a, int n)
{
    int current = 0, largest = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        current += a[i];
        largest = max(largest, current);
        if (current < 0)
            current = 0;
    }
    return largest;
}

int kadane_index(int *a, int n)
{
    int current = 0, largest = INT_MIN;
    int start = 0, last = 0, temp;
    // bool flag =false;
    for (int i = 0; i < n; i++)
    {
        current += a[i];
        if (current > largest)
        {
            last = i;
            largest = current;
            if (temp != start)
            {
                start = temp;
            }
        }
        if (current < 0)
        {
            current = 0;
            // flag = true;
            temp = i + 1;
        }
    }
    cout << "index1: " << start << "index2: " << last << '\n';
    return largest;
}

int main()
{
    int a[] = {-2, 3, 4, -1, 5, -12, 6, 1, 3};
    int n = sizeof(a) / sizeof(int);
    cout << kadane_index(a, n);
}
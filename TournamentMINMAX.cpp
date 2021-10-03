#include <bits/stdc++.h>
using namespace std;

struct minmax
{
    int min;
    int max;
};
int cn = 0;
struct minmax tournament(int *a, int low, int high)
{
    struct minmax current, b, c;
    int mid = (low + high) / 2;
    if (low == high)
    {
        current.max = a[low];
        current.min = a[low];
        return current;
    }
    b = tournament(a, low, mid);
    c = tournament(a, mid + 1, high);
    if (b.min > c.min)
    {
        current.min = c.min;
        cn++;
    }
    else
    {
        current.min = b.min;
        cn++;
    }
    if (b.max > c.max)
    {
        current.max = b.max;
        cn++;
    }
    else
    {
        current.max = c.max;
        cn++;
    }
    return current;
}

int main()
{
    int arr[] = {1000, 11, 445, 330, 3000};
    int arr_size = 5;
    struct minmax x = tournament(arr, 0, 5);
    cout << "min: " << x.min << ' ' << "max: " << x.max;
    cout << endl << cn;
}
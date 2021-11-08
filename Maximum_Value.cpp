#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int size;
        cin >> size;
        vector<long long> v(size);
        for (int i = 0; i < size; i++)
        {
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        long long max1 = v[size - 1] * v[size - 2] + v[size - 1] - v[size - 2];
        long long max2 = v[0] * v[size - 1] + v[0] - v[size - 1];
        long long max3 = v[1] * v[0] + v[1] - v[0];
        max1 = max(max(max2, max3), max1);
        cout << max1 << '\n';
    }
}
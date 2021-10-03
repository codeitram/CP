#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long x;
        cin >> x;
        long long xcopy = x;
        int noOfBits = 0;
        if (x == 0)
            noOfBits = 1;
        while (x)
        {
            noOfBits++;
            x >>= 1;
        }
        long long max = pow(2, noOfBits) - 1;
        if (max == xcopy)
            cout << max + 1 << '\n';
        else
            cout << pow(2, noOfBits - 1) << '\n';
    }
}


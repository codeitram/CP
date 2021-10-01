#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a;
        cin >> a;
        int acopy = a;
        int count = -1;
        while (acopy)
        {
            count++;
            acopy >>= 1;
        }

        int highest = pow(2, count);
        int secondHigh = highest / 2;
        int highDiff = highest - secondHigh;
        int noDiff = a - highest+1;
        if (highDiff > noDiff)
            cout << highDiff << '\n';
        else
            cout << noDiff << '\n';
    }
}
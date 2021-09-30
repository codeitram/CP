#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, x;
    cin >> a >> x;
    int result = 1;
    while (x)
    {
        if (x & 1)
        {
            result *= a;
        }
        a *= a;
        x >>= 1;
    }
    cout << result;
}
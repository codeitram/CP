#include <bits/stdc++.h>
using namespace std;

int main()
{
    // find the no of set bits in the given no
    int x;
    cin >> x;
    int count = 0;
    while (x) // this is the hack
    {
        count++;
        x = x & x - 1;
    }
    cout << count;
}

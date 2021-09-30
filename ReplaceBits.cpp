// Replace bit in N by M, from given poistion i and j
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 128, m = 10;
    int i = 2, j = 5;

    // create a mask like 1111000011 where 0 si from 2 to 5, so that we zero that position first
    int a = (-1) << j + 1;
    int b = 1 << i - 1;
    int mask = a | b;
    n = n & mask;
    if (i > 0)
        m = m << i - 1; // i can't be 1 0 then

    n = n | m;
    cout << n; // should be 148
}
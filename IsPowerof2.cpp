// power of 2 or not; except 0
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x;
    cin >> x;
    cout << ((x & x - 1) == 0 ? "Yes" : "No"); // Very INteresting remember it
}
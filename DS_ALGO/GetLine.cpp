#include <bits/stdc++.h>
using namespace std;

int main()
{
    // there are two variants of getline I know of
    char a[1000];
    // cin.getline(a, 1000, '\n'); // last parameter is optional here for char array only
    // cout<<a;
    string b;
    getline(cin, b, '*'); // also last is optional in here too. It works on string only
    cout << b;
}
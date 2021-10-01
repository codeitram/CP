#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        if (a != 0 and b != 0)
            cout << "Solution\n";
        else if (a == 0)
            cout << "Liquid\n";
        else if (b == 0)
            cout << "Solid\n";
    }
}
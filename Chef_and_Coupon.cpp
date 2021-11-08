#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int dc, cp, temp;
        cin >> dc >> cp;
        int day1 = 0, day2 = 0;
        for (int i = 0; i < 3; i++)
        {
            cin >> temp;
            day1 += temp;
        }
        for (int i = 0; i < 3; i++)
        {
            cin >> temp;
            day2 += temp;
        }
        int price1 = day1 + day2 + 2 * dc;
        int price2 = (day1 >= 150 ? day1 : day1 + dc) + (day2 >= 150 ? day2 : day2 + dc) + cp;
        if (price2 < price1)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
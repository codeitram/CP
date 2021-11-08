#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int size, allowed;
        cin >> size >> allowed;
        string s;
        // cin.ignore();
        cin >> s;

        vector<int> v(size);
        for (int i = 0; i < size; i++)
        {
            v[i] = s[i] - '0';
        }
        int error = 0;
        int intialzerocount = 0;
        int lastzerocount = 0;
        for (int i = 0; i < size - 1; i++)
        {
            if (v[i] == 0)
                intialzerocount++;
            else
                break;
        }

        for (int i = size - 1; i >= 0; i--)
        {
            if (v[i] == 0)
                lastzerocount++;
            else
                break;
        }

        for (int i = 0; i < size - 1;)
        {
            int temp = 0;
            if (v[i] == 1)
            {
                i++;
                while (v[i] == 0)
                {
                    i++;
                    temp++;
                    if (i >= size)
                        break;
                }
                if (temp > allowed and v[i] == 1)
                    error++;
            }
            else
                i++;
        }
        if (error == 1 && intialzerocount + lastzerocount <= allowed)
            cout << "YES\n";
        else if (error == 0)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}

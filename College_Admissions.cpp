// TODO

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int noc, nos;
        cin >> noc >> nos;
        vector<int> roc(noc);
        for (int i = 0; i < noc; i++)
            cin >> roc[i];
        vector<int> ros(nos);
        for (int i = 0; i < n; i++)
            cin >> ros[i];
    }
}
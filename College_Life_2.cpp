#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        long long total = 0;
        int season;
        cin >> season;
        vector<int> intro_length(season);
        for (int i = 0; i < season; i++)
            cin >> intro_length[i];

        for (int i = 0; i < season; i++)
        {
            int noOfEpisodes;
            cin >> noOfEpisodes;
            while (noOfEpisodes--)
            {
                int temp;
                cin >> temp;
                total += (temp - intro_length[i]);
            }
            total += intro_length[i];
        }
        cout << total << '\n';
    }
}
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> s{2, 1, 3, -2, 10, 2, 3, 4, 5};
    auto start_time = clock();
    sort(s.begin(), s.end());
    auto end_time = clock();
    cout << "Time Taken: " << end_time - start_time; // IN millseconds
}
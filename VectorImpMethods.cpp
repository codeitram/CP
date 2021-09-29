#include <bits/stdc++.h>
using namespace std;

int main()
{
    // 1.Fill Constructor
    vector<int> v(10, 2); // 10 elements intialized with 2
    for (int i : v)
        cout << i << ' ';

    v.pop_back(); // 2.delete last element without returning it.
    v[v.size() - 1] = 10;

    int x = v.back(); // 3.also v.front()
    cout << x;        // should be 10

    v.push_back(12);

    cout << v.at(v.size() - 1); // 4. loo .at()

    // 5. 2D array using vector
    vector<vector<int>> vv = {{1, 2, 3, 3}, {1}, {2, 32, 3}};
    vv.push_back({2, 3, 4});
    for (int i = 0; i < vv.size(); i++)
    {
        for (int i : vv[i])
        {
            cout << i << ' ';
        }
    }
    cout << endl;

    // 6. This also works for sure
    int a[] = {1, 2, 3, 4, 5};
    for (auto i : a)
        cout << i << ' ';
    // 7. capacity tells total elements(not size) occupied by array and size about currently used.
    cout << vv.capacity();
    // cout<<sizeof(vv);
}
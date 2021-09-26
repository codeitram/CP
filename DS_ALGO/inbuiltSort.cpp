#include <bits/stdc++.h>
using namespace std;

bool descending(int a, int b)
{
    return a > b;
}
int main()
{
    int a[] = {-2, 3, 4, -1, 5, -12, 6, 1, 3};
    for (auto i : a)
        cout << i << ' ';
    cout << '\n';
    // first way to sort in ascending;
    int n = sizeof(a) / sizeof(int);
    sort(a, a + n);

    for (auto i : a)
        cout << i << ' ';
    cout << '\n';

    // how to sor in descending order
    // option 1:
    // reverse(a, a + n); // since already sorted in asc, so just reverse

    for (auto i : a)
        cout << i << ' ';
    cout << '\n';

    // option 2:
    // sort(a, a + n, greater<int>()); // passing comprator function

    for (auto i : a)
        cout << i << ' ';
    cout << '\n';

    sort(a, a + n, descending); // passing greater fucntion as ref to works as comprator

    for (auto i : a)
        cout << i << ' ';
    cout << '\n';
}
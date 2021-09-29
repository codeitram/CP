#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v = {1, 2, 3, 43, 45, 78};

    // 1.find()
    vector<int>::iterator x = find(v.begin(), v.end(), 43);
    if (x == v.end())
        cout << "Not Found";
    else
        cout << x - v.begin() << endl;

    // the same above can be also done as follows
    auto y = find(v.begin(), v.begin() + v.size(), 43);
    cout << y - v.begin() << endl;
    // 2. search fucntion
    vector<int> a = {3, 43, 46};
    auto b = search(v.begin(), v.end(), a.begin(), a.begin() + 3);

    if (b == v.end())
        cout << "Sequence not found\n";
    else
        cout << b - v.begin() << endl;

    // 3. binary_search function
    vector<int> c = {10, 20, 22, 25, 89, 99, 102, 823, 2384};
    auto d = binary_search(c.begin(), c.end(), 23); // returns 1 if it is present otherwise 0
    cout << d << endl;

    // 4.lower_bound(), Returns an iterator pointing to the first element in the range [first,last) which does not
    // compare less than val.

    auto ab = lower_bound(c.begin(), c.end(), 21);
    if (ab == c.end())
        cout << "NOT FOUND\n";
    cout << ab - c.begin() << endl;

    // 5. upper_bound(), Returns an iterarator pointing to the first element greater than val, so itcan't be equal.
    cout << (upper_bound(c.begin(), c.end(), 102) - c.begin()) << endl;
}
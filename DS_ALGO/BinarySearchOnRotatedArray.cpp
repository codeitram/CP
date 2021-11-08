#include <bits/stdc++.h>
using namespace std;

int rotated_search(vector<int> &a, int key)
{
    int s = 0, e = a.size() - 1;

    while (s <= e)
    {
        int mid = (s + e) / 2;
        if (a[mid] == key)
            return mid;
        else if (a[s] <= a[mid])
        {
            if (a[s] <= key and a[mid] >= key)
                e = mid - 1;
            else
                s = mid + 1;
        }
        else
        {
            if (a[mid] <= key and a[e] >= key)
                s = mid + 1;
            else
                e = mid - 1;
        }
    }
    return -1;
}

int BinarySearch(vector<int> &a, int s, int e, int k) // different loop condition for same BS
{
    int mid;
    while (s < e - 1)
    {
        mid = (s + e) / 2;
        if (a[mid] <= k)
            s = mid;
        else
            e = mid;
    }
    if (a[s] == k)
        return s;
    if (a[e] == k)
        return e;
    return -1;
}

int rotatedSearch(vector<int> &a, int k)
{
    int s = 0, e = a.size() - 1;
    int mid;
    while (s < e - 1) // using binary search to find pivot element
    {
        mid = (s + e) / 2;
        if (a[s] <= a[mid])
            s = mid;
        else
            e = mid;
    }
    if (a[s] < a[e])
        s++;
    if (k >= a[0])
        return BinarySearch(a, 0, s, k);
    else
        return BinarySearch(a, s, a.size() - 1, k);
}
int main()
{

    vector<int> a{9, 5, 6, 7, 0, 1, 2, 3};
    int key;
    cin >> key;
    cout << rotated_search(a, key) << endl;
    cout << rotatedSearch(a, key) << endl;
    return 0;
}
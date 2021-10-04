#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &a, int s, int e)
{
    int i =s, j = e, k;
    int mid = (s + e) / 2;
    k = mid + 1;
    vector<int> temp;
    while (i <= mid and k <= e)
    {
        if (a[i] > a[k])
        {
            temp.push_back(a[k]);
            k++;
        }
        else
        {
            temp.push_back(a[i]);
            i++;
        }
    }
    while(i<=mid)
    {
        temp.push_back(a[i]);
        i++;
    }
    while(k<=e)
    {
        temp.push_back(a[k]);
        k++;
    }
    for(int i=s,j=0; i<=e; i++,j++)
    {
        a[i]=temp[j];
    }
}

void mergesort(vector<int> &a, int i, int e)
{
    if (i >= e)
        return;
    int mid = (i + e) / 2;
    mergesort(a, i, mid);
    mergesort(a, mid + 1, e);
    merge(a, i, e);
}
int main()
{
    vector<int> a{0, 1, 33, 2, 9, -7, 5, 8};
    mergesort(a, 0, a.size() - 1);
    for (int &i : a)
        cout << i << ' ';
}

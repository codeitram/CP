#include <bits/stdc++.h>
using namespace std;

void negfirst(vector<int> &a, int n)
{
    int i =0, j= 0;
    while(i<n and j<n)
    {
        if(a[j]<0 and a[i]>0) swap(a[i],a[j]);
        if(a[i]<0)
        {
            i++;
        }
        j++;

    }
}
int main()
{
    vector<int> s{-12, 11, -13, -5, 6, -7, 5, -3, -6};
    negfirst(s,s.size());
    for(auto i: s)cout<<i<<' ';
}
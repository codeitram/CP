//Given a 2d array sorted both row and column wise, fina a given element in it

#include <bits/stdc++.h>
using namespace std;

pair<int,int> stairCaseSearch(int a[][4],int n, int m, int key)
{
    // if(key>a[n-1][m-1] or key<a[0][0]) return {-1,-1}; //this sanity check is optional 
    for(int i=n-1,j=0; i>=0  and j<m;)
    {
        if(a[i][j]==key) return {i,j};
        else if(a[i][j]>key) i--;
        else j++;
    }
    return {-1,-1};
}
int main()
{
    int a[][4]={{10,20,30,40},{15,25,35,45},{27,29,37,48},{32,33,39,50}};
    int n=4,m=4;
    pair<int,int> x= stairCaseSearch(a,n,m,0);
    cout<<x.first<<' '<<x.second;
}
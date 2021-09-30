#include <bits/stdc++.h>
using namespace std;

int main()
{
    // int x;
    // cin>>x;
    // int shift = sizeof(int)*8-1;
    // int i = 1<<shift;
    // int result =0;
    // shift++;
    // while(shift--)
    // {
    //     result =result*10 ;
    //     if((x&i)!=0)result+=1;
    //     x<<=1;
    // }
    // cout<<result;

    // Method2:
    int x;
    cin >> x;
    int base = 1;
    int result = 0;
    while (x)
    {
        result += (x & 1) * base;
        base *= 10;
        x >>= 1;
    }
    cout << result;
}
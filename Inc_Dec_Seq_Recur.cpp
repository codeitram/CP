#include <bits/stdc++.h>
using namespace std;

void dec(int x)
{
    if (x == 0)
        return;
    cout << x << ' ';
    dec(x - 1);
}
void inc(int x)
{
    if (x == 0)
        return;
    inc(x - 1);
    cout << x << ' ';
}
int main()
{
    dec(5);
    cout << endl;
    inc(5);
}
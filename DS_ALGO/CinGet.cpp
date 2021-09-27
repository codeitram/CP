#include <bits/stdc++.h>
using namespace std;

int main()
{
    char a[100];
    int i = 0;
    // Method 1:
    // this works because assignment opr returns the value it just assigned
    while ((a[i++] = cin.get()) != '*')
        ; // if !=='\n' then remove next line
    a[i] = 0;

    // easy and suggested way that same thig as above is Method2
    i = 0;
    int temp = cin.get();
    while (temp != 10) // LOL 10 is the ascii of char '\n'; -1 is for EOF
    {
        a[i++] = temp;
        temp = cin.get();
    }
    a[i] = 0;
    cout << a;
}
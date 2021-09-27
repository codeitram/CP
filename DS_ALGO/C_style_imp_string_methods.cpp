#include <bits/stdc++.h>
using namespace std;

int main()
{
    char a[1000] = "ram";
    char b[1000];
    // string length, so without counting '\n'
    cout << strlen(a) << endl;
    // strcpy to copy 2nd arg to 1st arg
    strcpy(b, a);
    cout << b << endl;
    // strcmp compares 1st to 2nd arg, returns 0 if same
    cout << strcmp(a, b);
    //strcat to add two string, it will return new string so you should store it
    // char c[] = strcat(a,b); // this won't work
    char c[100];
    strcpy(c,strcat(a,b));
    cout<<c<<endl;
}
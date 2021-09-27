#include <bits/stdc++.h>
using namespace std;
string compress(string &s)
{
    string com;
    for (int i = 0; i < s.size(); i++)
    {
        int count = 1;
        while (i < s.size() and s[i] == s[i + 1])
        {
            count++;
            i++;
        }
        com += s[i];
        com += to_string(count);
    }
    return com.size() < s.size() ? com : s;
}

int main()
{
    string s1 = "aaabbccddee";
    cout << s1 << endl;
    cout << compress(s1);
}
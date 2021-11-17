#include <bits/stdc++.h>
using namespace std;

bool compare(string s1, string s2)
{
    if (s1.length() == s2.length())
    {
        return s1 < s2; // simply think this of order which you want in sorted item
    }
    else
        return s1.length() < s2.length();
}

void findSubset(char *input, char *output, int i, int j, vector<string> &list)
{
    // base case
    if (input[i] == '\0')
    {
        output[j] = '\0';
        string temp(output);
        list.push_back(temp);
        return;
    }
    // recursion
    output[j] = input[i];
    findSubset(input, output, i + 1, j + 1, list);
    findSubset(input, output, i + 1, j, list);
}

int main()
{
    char input[100];
    char output[100];
    cin >> input;
    vector<string> list;
    findSubset(input, output, 0, 0, list);
    sort(list.begin(), list.end(), compare);
    for (auto s : list)
        cout << s << ',';
}
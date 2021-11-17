#include <bits/stdc++.h>
using namespace std;

void permutation(char *input, int i, int n)
{
    if (input[i] == '\0')
    {
        cout << input << endl;
        return;
    }
    for (int j = i; j < n; j++)
    {
        swap(input[i], input[j]);
        permutation(input, i + 1, n);
        swap(input[i], input[j]);
    }
}
int main()
{
    char input[100];
    cin >> input;
    int size = 0;
    int i = 0;
    while (input[i++] != '\0')
        size++;
    permutation(input, 0, size);
}
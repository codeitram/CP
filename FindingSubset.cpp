#include <bits/stdc++.h>
using namespace std;

void printSubsets(char *input, char *output, int i, int j)
{
    // base case
    if (input[i] == '\0')
    {
        output[j] = '\0';
        cout << output << endl;
        return;
    }
    // recursive case
    output[j] = input[i];
    printSubsets(input, output, i + 1, j + 1);
    printSubsets(input, output, i + 1, j);
}

int main()
{
    char input[100];
    char output[100];
    cin >> input;
    printSubsets(input, output, 0, 0);
}
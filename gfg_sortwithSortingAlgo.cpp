// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    void sort012(int a[], int n)
    {
        // coode here
        int c[3] = {0, 0, 0};
        for (int i = 0; i < n; i++)
        {
            c[a[i]]++;
        }
        cout << c[0] << c[1] << c[2] << endl;
        for (int i = 0; i < 3; i++)
        {
            while (c[i])
            {
                cout << i << ' ';
                c[i]--;
            }
        }
    }
};

// { Driver Code Starts.
int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        int a[100];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }

        cout << endl;
    }
    return 0;
}

// } Driver Code Ends
// { Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
void heapify(int a[], int n, int i)
{
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int smallest = i;
    if (left < n and a[left] < a[i])
        smallest = left;
    if (right < n and a[right] < a[smallest])
        smallest = right;
    if (smallest != i)
    {
        swap(a[i], a[smallest]);
        heapify(a, n, smallest);
    }
}
class Solution
{
  public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k)
    {
        // code here
        for (int i = r - l - 1; i >= 0; i--)
        {
            heapify(arr, r - l + 1, i);
        }

        for (int i = 1; i < k; i++)
        {
            arr[0] = INT_MAX;
            heapify(arr, r - l + 1, 0);
        }
        return arr[0];
    }
};

// { Driver Code Starts.

int main()
{
    int test_case;
    cin >> test_case;
    while (test_case--)
    {
        int number_of_elements;
        cin >> number_of_elements;
        int a[number_of_elements];

        for (int i = 0; i < number_of_elements; i++)
            cin >> a[i];

        int k;
        cin >> k;
        Solution ob;
        cout << ob.kthSmallest(a, 0, number_of_elements - 1, k) << endl;
    }
    return 0;
} // } Driver Code Ends
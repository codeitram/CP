#include <bits/stdc++.h>
using namespace std;

void minheapify(int arr[], int n, int i) // min heap
{
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int smallest = i;
    if (left < n and arr[left] < arr[i])
        smallest = left;
    if (right < n and arr[right] < arr[smallest])
        smallest = right;
    if (smallest != i)
    {
        swap(arr[i], arr[smallest]);
        minheapify(arr, n, smallest);
    }
}

void maxheapify(int arr[], int n, int i) // max heap not tested
{
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int largest = i;
    if (left < n and arr[left] > arr[i])
        largest = left;
    if (right < n and arr[right] > arr[largest])
        largest = right;
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        maxheapify(arr, n, largest);
    }
}

void buildMinHeap(int arr[], int n)
{
    int parent = (n - 2) / 2;
    for (int i = parent; i >= 0; i--)
    {
        minheapify(arr, n, i);
    }

    // Method 2: This is wrong try for {12,5,787,1,23} to know why
    // int parent = (n - 2) / 2;
    // for (int i = parent; i >= 0; i--)
    // {
    //     int child1 = 2 * i + 1;
    //     int child2 = 2 * i + 2;
    //     if (arr[i] > arr[child1])
    //         swap(arr[i], arr[child1]);
    //     if (arr[i] > arr[child2])
    //         swap(arr[i], arr[child2]);
    // }
}
int main()
{
    int arr[] = {12, 5, 787, 1, 23};

    // calculating size of array
    int n = sizeof(arr) / sizeof(arr[0]);
    buildMinHeap(arr, n);

    cout << "Array representation before buildHeap is: " << endl;

    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";

    cout << endl;
}
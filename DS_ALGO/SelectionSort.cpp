#include <bits/stdc++.h>

using namespace std;

void selectionSort(int *a, int n)
{
	for(int i=0;i<n;i++)
	{
		int minIndex; int min = INT_MAX;
		for(int j=i; j<n; j++)
		{
			if(a[j]<min) 
			{	
				minIndex = j; min = a[j];
			}
		}
		swap(a[i],a[minIndex]);
	}
}

int main()
{
	int a[] = {-2,3,4,-1,5,-12,6,1,3};
	int n = sizeof(a)/sizeof(int);
	
	selectionSort(a,n);
	for(int i=0; i<n; i++) cout<<a[i]<<' ';
}
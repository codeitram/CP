#include<bits/stdc++.h>

using namespace std;

// void swap(int &a, int &b)
// {
	// int c;
	// c = a;
	// a = b;
	// b =c;
// }

void bubbleSort(int *a, int n)
{
	for(int i=0; i<n; i++) // i<n
	{
		for(int j=0; j<n-1; j++) //j<n-1
		{
			if(a[j]>a[j+1]) swap(a[j],a[j+1]);
		}
	}
}
int main()
{
	int a[] = {-2,3,4,-1,5,-12,6,1,3};
	int n = sizeof(a)/sizeof(int);
	bubbleSort(a,n);
	for(int i=0; i<n; i++)
		cout<<a[i]<<' ';
	
}
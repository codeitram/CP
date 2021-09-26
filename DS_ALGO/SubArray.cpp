#include <bits/stdc++.h>

using namespace std;

void printSubArray(int a[], int n) //also print the sum of largest subArray
{
	int sum =0;
	int largest= INT_MIN;
	for(int i=0; i<n; i++)
	{
		for(int j=i; j<n; j++)
		{
			for(int k=i; k<=j; k++)
			{
				cout<<a[k]<<',';
				sum+=a[k];
			}
			cout<<'\n';
			largest = sum>largest?sum:largest;
			sum =0;
		}
	}
	cout<<"largest is"<<largest;	
}

int main()
{
	int a[]= {10,20,30,40,50,60};
	int n = sizeof(a)/sizeof(int);
	printSubArray(a,n);
}
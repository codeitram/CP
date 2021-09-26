#include <bits/stdc++.h>

using namespace std;

int main()
{
	int a[] = {10,22,321,421,523};
	int x = 31;
	int count =0;
	for(int i =0; i<=x; i++)
	{
		cout<<'{';
		int x = i;
		int print = false;
		while(x)
		{
			bool flag = false;
			flag = x&1;
			x = x>>1;
			count++;
			if(flag)
			{
				if(print) cout<<',';
				cout<<a[count-1];
					print = true;
				
			}
		
		}
		cout<<'}';
		cout<<'\n';
		count =0;
	}
}
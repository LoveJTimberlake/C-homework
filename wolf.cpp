#include<iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int * a = new int [n];
	for(int I = 0; I < n; I++)
		{
			a[I] = false;
		}
	int I = 0, k = 1000000;
	for(int b = 0, s = 1; b < k; b++,s++)
	      {
		I = I%n;
		a[I] = true;
		I += (1+s);
	      }
	for(int m = 0; m < n; m++)
	{
		if(!a[m]) cout<<m+1<<' ';
	}
	system("pause");
}

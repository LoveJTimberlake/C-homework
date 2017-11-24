#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	int a[3][5];
	int * p = a[0];
	for(int i = 0; i < 15;i++)
	{
		cin>>*(p+i);
	}
	int c[5][3];
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 5; j++)
		{
			c[j][i] = a[i][j];
		}
	}
	int b[3][3];
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			int sum = 0;
			for(int k = 0; k < 5; k++)
			{
					sum += a[i][k] * c[k][j];
			}
			b[i][j] = sum;
		}
	}
	for(int s = 0; s < 15; s++)
	{
		cout<<*(p+s)<<setw(5)<<' ';
		if((s+1)%5 == 0) cout<<endl;
	}
	cout<<endl;
	int * m = c[0];
	for(int s = 0; s < 15; s++)
	{
		cout<<*(m+s)<<setw(3)<<' ';
		if((s+1)%3 == 0) cout<<endl;
	}
	cout<<endl;
	int * q = b[0];
	for(int s = 0; s < 9; s++)
	{
		cout<<*(q+s)<<setw(3)<<' ';
		if((s+1)%3 == 0) cout<<endl;
	}
	system("pause");
}
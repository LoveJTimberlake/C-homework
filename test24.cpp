#include<iostream>
using namespace std;
void Compare(int a[], int b[])
{
	int m1,m2;
	for(int i = 9; i >= 0; i--)
	{
		if(a[i] != 0) 
		{	m1 = i;
			break;
		}
	}
	for(int i = 9; i >= 0; i--)
	{
		if(b[i] != 0) 
		{	m2 = i;
			break;
		}
	}
	if(m1 == m2)
	{
		for(int i = 0; i <= m1; i++)
		{
			if(a[i] > b[i]) 
			{
				cout<<"First number is bigger";
				return;
			}
			else if(a[i] < b[i])
			{
				cout<<"Second number is bigger";
				return;
			}
		}
		cout<<"Equal";
	}
	else if(m1 > m2) 
	{
		cout<<"First number is bigger";
		return;
	}
	else 
	{
		cout<<"Second number is bigger";
		return;
	}
}

int main()
{
	int a[10],b[10];
	for(int i = 0; i < 10; i++)
	{
		cin>>a[i];
	}
	for(int i = 0; i < 10; i++)
	{
		cin>>b[i];
	}
	Compare(a,b);
	system("pause");
}
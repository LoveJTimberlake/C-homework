#include<iostream>
using namespace std;

int main()
{
	char  a[101];
	cin>>a;
	int i = 0;
	while(a[i] != '#')
	{
		i++;
	}
	int n = i - 1;
	for(;n >=0;n--)
	{
		cout<<a[n];
	}
	system("pause");
}
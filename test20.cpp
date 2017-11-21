#include<iostream>
using namespace std;

int main()
{
	int *a = new int[33];
	int counter = 0;
	for(int i = 0; i<100; i++)
	{
		if(!(i%3) && (i%10 == 6))
		{
			a[counter] = i;
			counter ++;
		}
	}
	for(int i = 0; i < sizeof(a); i++)
	{
		cout<<a[i]<<' ';
	}
	system("pause");
}
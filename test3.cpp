#include<iostream>
#include<cmath>
#include<stdio.h>
using namespace std;

int main()
{
	int x;
	cout<<"Please tell me a five-bit number";
	cin>>x;
	int a[5];
	for(int i= 0; i < 5; i++)
	{
		int k = x / (int)pow(10,float(4-i));
		a[i] = k;
		x -= k * (int)pow(10,float(4-i));
		cout<<a[i]<<"   ";
	}
	system("pause");
}


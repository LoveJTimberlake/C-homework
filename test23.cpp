#include<iostream>
using namespace std;

int main()
{
	char p[10000];
	cin>>p;
	for(int i = 0; p[i] != '\0'; i++)
	{
		if(p[i] <= 'z' && 'a' <= p[i])
		{
			p[i] -= 32;
		}
		cout<<p[i];
	}
	system("pause");
	
}
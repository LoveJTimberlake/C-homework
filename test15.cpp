#include<iostream>
using namespace std;

void reverse()
{
	int n;
	cin>>n;
	if(n == -1) return ;
	reverse();
	cout<<n<<"  ";
}

int main()
{
	reverse();
	system("pause");
}
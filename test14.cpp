#include<iostream>
using namespace std;

double Ackman(int m, int n)
{
	if(m == 0) return n+1;
	else if(m > 0 && n == 0)	return Ackman(m-1,1);
	else 
	{
		return Ackman(m-1,Ackman(m,n-1));
	}
}

int main()
{
	int m,n;
	cin>>m>>n;
	cout<<Ackman(m,n);
	system("pause");
}
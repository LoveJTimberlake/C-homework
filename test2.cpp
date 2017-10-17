#include<iostream>
using namespace std;

int main()
{
	int x,y;
	cout<<"Please tell me two numbers:";
	cin>>x>>y;
	cout<<"Sum:"<<x+y<<endl;
	cout<<"Difference:"<<x - y<<endl;
	cout<<"Product:"<<x*y<<endl;
	cout<<"Quotient:"<<float(x/y);
	system("pause");
}
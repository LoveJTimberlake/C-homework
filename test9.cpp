#include<iostream>
using namespace std;

double max(double a, double b, double c)
{
	return max(max(a,b),max(b,c));
}
void main()
{
	cout<<max(3.2,7.4,4.5)<<endl;
	system("pause");
}
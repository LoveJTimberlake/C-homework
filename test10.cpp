#include<iostream>
using namespace std;

double shouFei(double m)
{
	return (0.01 * m <= 50 ? 0.01*m:50);
}
void main()
{
	cout<<"输入汇款金额：";
	double m;
	cin>>m;
	cout<<"本次汇款收费："<<shouFei(m)<<endl;
	
	system("pause");
}
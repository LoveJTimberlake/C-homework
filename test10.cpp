#include<iostream>
using namespace std;

double shouFei(double m)
{
	return (0.01 * m <= 50 ? 0.01*m:50);
}
void main()
{
	cout<<"�������";
	double m;
	cin>>m;
	cout<<"���λ���շѣ�"<<shouFei(m)<<endl;
	
	system("pause");
}
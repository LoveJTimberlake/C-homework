#include<iostream>
using namespace std;

int main()
{
	int x1,x2 = 0,x3;
	cout<<"Side 1"<<"\t"<<"Side 2"<<"\t"<<"Side 3"<<endl;
	for(x1 = x2 ; x1 <= 500; x1++)
	{
		for(x2 = 1; x2 <= 500; x2++)
		{
			for(x3 = 1 ;x3 < x2 + x1 && x3 <= 500; x3++)
			{
				if(x3 * x3 == x1* x1 + x2 * x2) 
				{
					cout<<x1<<'\t'<<x2<<'\t'<<x3<<endl;
				}
			}
		}
	}
	system("pause");
}
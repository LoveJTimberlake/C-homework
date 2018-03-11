#include<iostream>
using namespace std;
#include"Matrix.h"

int main()
{
	Matrix M1;
	Matrix M2;
	cout<<M1 + M2 + M1 + M1 * 2;
	Matrix M3;
	cout<<M3 * M2;
	if(M2==M3) 
	{
		M2 += M1;
		cout<<M2;
	}
	system("pause");
}
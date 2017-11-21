#include<iostream>
using namespace std;

int Count(double a[],int n)
{
	double sum = 0;
	for(int i = 0; i < n;i++)
	{
		sum+=a[i];
	}
	double aver = sum/n;
	int  counter = 0;
	for(int i = 0; i < n;i++)
	{
		if(a[i] >= aver) counter++;
	}
	return counter;
}

void main()

{ 

    int c; 

    double a[10] = { 34,54,75,86,53,45,34,45,34,45 }; 

    c = Count(a, 10); 

    cout << "数组中大于等于所有元素平均值的元素个数为：" << c;
	system("pause");
}

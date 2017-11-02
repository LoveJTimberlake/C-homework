#include<iostream>
using namespace std;

int mySum(int m, int n);

int main()
{
	cout<<mySum(1,5)<<endl;
	system("pause");
	return 0;
}

int mySum(int m, int n)
{
	int sum = 0,temp_sum;
	for(; m<= n; m++)
	{
		temp_sum = 1;
		for(int j = 1; j <= m; j++)
		{
			temp_sum *= j;
		}
		sum += temp_sum;
	}
	return sum;
}
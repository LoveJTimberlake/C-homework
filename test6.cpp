#include<iostream>
using namespace std;

int main()
{
	double pi = 0.0;
	cout << "term";
	for (int i = 0; i < 40; i++)
	{
		cout << ' ';
	}
	cout << "pi" << endl;
	for (double i = 1; i < 1001; i++)
	{
		cout << i;
		for (int j = 0; j < 40; j++)
		{
			cout << ' ';
		}
		pi += pow(double(-1), i - 1)*(4 / (2 * i - 1));
		cout << pi << endl;
	}
	system("pause");
}
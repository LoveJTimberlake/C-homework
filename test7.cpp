#include<iostream>
using namespace std;

int main()
{
	for (int x = 1; x < 1001; x++)
	{
		int y = x * x;
		if (x < 10)
		{
			if (!((y - x) % 10)) cout << x << ' ';
		}
		else if (x< 100)
		{
			if (!((y - x) % 100)) cout << x << ' ';
		}
		else if (x <1000)
		{
			if (!((y - x) % 1000)) cout << x << ' ';
		}
	}
	system("pause");
}
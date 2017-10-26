#include<iostream>
using namespace std;

int main()
{
	int x,a,b,c,d,y;
	cin >> x;
	a = x/1000;
	b = x % 1000 / 100;
	c = x % 1000 % 100 / 10;
	d = x - a * 1000 - b * 100 - c * 10;
	y = (c + 7) % 10 * 1000 + (d + 7) % 10 * 100 + (a + 7) % 10 * 10 + (b + 7) % 10;
	if ((c + 7) % 10 == 0) cout << 0;
	cout << y;
	system("pause");
}
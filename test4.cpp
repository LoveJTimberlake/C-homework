#include<iostream>  
using namespace std;  
 int main()  
{  
	double a, b, c;  
	cout << "Please tell me three numbers and I will tell you whether they can form a triangle:" << endl;  
	cin >> a >> b >> c;  
	cout<<((a + b > c && a + c > b && b + c > a) ? char('Y') : char('N'));  
	system("pause");  
}  

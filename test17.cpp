#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
	string s;
	int n;
	cin>>n;
	s = "";
	for(int a = n; a; a = a/2)
	{
		s = s + (a%2?'1':'0');
	}
	std::reverse(s.begin(),s.end());
	cout<<s;
	system("pause");
}
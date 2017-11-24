#include<iostream>
using namespace std;
int a[10];
bool flag = false;
void Loop_Search(int begin, int end)
{
	int s;
	cout<<"Number to search:(Using Loop)";
	cin>>s;
	while(true)
	{
		if(end - begin < 2 && a[end] != s && a[begin] != s) 
			{
				cout<<"Not existed"<<endl;;
				break;			
			}
		if(s == a[(begin+end)/2]) 
			{	
				cout<<(begin+end)/2+1<<"th element"<<endl;
				break;
			}
		else if(s > a[(begin+end)/2]) end = (begin+end)/2;
		else if(s < a[(begin+end)/2]) begin = (begin+end)/2 + 1;
	}
}

void recursion(int s,int begin,int end)
{
	
	if(s == a[(begin+end)/2]) 
		{
			cout<<(begin+end)/2+1<<"th element"<<endl;
			flag = true;
			return;		
		}
	if(end - begin < 2 && a[end] != s && a[begin] != s) return;
	else if(s > a[(begin+end)/2]) 
		{	
			return recursion(s,begin,(begin+end)/2);			
		}
	else if(s < a[(begin+end)/2]) 
		{
			return recursion(s,(begin+end)/2 + 1,end);
		}
	
}
int main()
{
	for(int i = 0; i < 10; i++)
	{
		cin>>a[i];
	}
	Loop_Search(0,9);
	cout<<endl;
	int s;
	cout<<"Number to search:(Using recursion)";
	cin>>s;
	recursion(s,0,9);
	if(flag == false) cout<<"Not Existed";
	system("pause");
}
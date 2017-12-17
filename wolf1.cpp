#include<iostream>
using namespace std;

struct Node
{
	bool s;
	Node *next;
};
int main()
{
	Node * head = new Node;
	head->s = false;
	head->next = NULL;
	int n ;
	cin>>n;
	Node * a = new Node;
	a = head;
	for(int i = 0; i < n; i++)
	{
		Node * p = new Node;
		p->s = false;
		a->next = p;
		p->next = head->next;
		a = p;
	}
	int x = 1000000;
	Node * temp = head->next;
	int pace;
	for(int i = 0, pace = 2; i < x; i++,pace++)
	{
		temp->s = true;
		for(int q = 0; q < pace; q++)
		{
			temp = temp->next;		
		}
	}
	Node * temp1 = head->next;
	for(int i = 0; i < n; i++)
	{
		if(!temp->s) cout<<i+1<<' ';
	}
	system("pause");
}
   
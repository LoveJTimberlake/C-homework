#include<iostream>  
using namespace std;  

void borrow(char a[])
{
	int i,j,k;
	int counter = 0;
	for(i = 1; i <= 5; i++)
	{
		for(j = 1; j <= 5; j++)
		{
			for(k = 1; k <= 5; k++)
			{
				if(i != j && i != k && j != k) 
				{
					cout<<"A:Book"<<i<<'\t'<<"B:Book"<<j<<'\t'<<"C:Book"<<k<<endl;
					counter ++;
				}
			}
		}
	}
	cout<<"Totally "<<counter<<" way to borrow books"<<endl;
}

int main()
{
	char * man = "ABC";
	borrow(man);
	system("pause");
}
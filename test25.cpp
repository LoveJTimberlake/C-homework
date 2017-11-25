#include<iostream>
using namespace std;

int row,col;
int counter = 0;
void FindMax(int *a[],int i, int j,int s1[],int s2[])
{
	bool flag = true;
	for(int s = 0 ; s < col; s++)
	{
		if(a[i][j] >= a[i][s]) continue;
		else
		{
			flag = false;
			break;
		}
	}
	if(flag == true) 
	{
		for(int k = 0 ; k < row; k++)
		{
			if(a[i][j] <= a[k][j]) continue;
			else
			{
				flag = false;
				break;
			}
		}
	}
	if(flag)
	{
		s1[counter] = i;
		s2[counter] = j;
		counter++;
	}
}

int main()
{
	cout<<"Row of matrix: ";
	cin>>row;
	cout<<endl;
	cout<<"Column of matrix: ";
	cin>>col;
	cout<<endl;
	int * s1 = new int[row];
	int * s2 = new int[col];
	int ** a = new int *[row];
	for(int i = 0; i < row; i ++)
	{
		a[i] = new int[col];
	}

	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < col; j ++)
		{
			cin>>a[i][j];
		}
	}
	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < col; j ++)
		{
			FindMax(a,i,j,s1,s2);
		}
	}
	for(int m = 0 ; m < counter; m++)
	{
		cout<<s1[m]<<"  "<<s2[m]<<endl;
	}
	if(counter == 0) cout<<"Not Existed such a point"<<endl;
	system("pause");
}
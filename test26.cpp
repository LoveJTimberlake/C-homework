#include<iostream>
using namespace std;


int main()
{
	bool floor[20][20] = {false};
	int loc[2] = {0,0};
	int command;
	char e;
	bool pen = false;
	char direct[4] = {'u','r','d','l'};
	char d = 'r';
	while(cin>>command)
	{
		
		if(command == 9) break;
		else if(command == 1) pen = false;
		else if(command == 2) pen = true;
		else if(command == 3) 
		{
			switch(d){
				case 'u': d = 'r';break;
				case 'r': d = 'd';break;
				case 'd': d = 'l';break;
				case 'l': d = 'u';break;
			}
		}
		else if(command == 4) 
		{
			switch(d)
			{
				case 'u': d = 'l';break;
				case 'l': d = 'd';break;
				case 'd': d = 'r';break;
				case 'r': d = 'u';break;
			}
		}
		else if(command == 5)
		{
			int length;
			cin>>e>>length;
			if(d == 'u')
			{
				if(length>loc[0]+1)
				{
					cout<<"Error"<<endl;
					continue;
				}
				if(pen)
				{
					int i;
					for(i = loc[0]; loc[0] - i + 1<=length; i--)
					{
						floor[i][loc[1]] = true;
					}
					loc[0] = ++i;
				}
				else
				{
					loc[0] = loc[0] - length + 1;
				}
			}
			else if(d == 'r')
			{
				if(length > 20 - loc[1])
				{
					cout<<"Error"<<endl;
					continue;
				}
				if(pen)
				{
					int z;
					for(z = loc[1]; z - loc[0] + 1 <= length;z++)
					{
						floor[loc[0]][z] = true;
					}
					loc[1] = --z;
				}
				else loc[1] = loc[1] + length - 1;
			}
			else if(d == 'd')
			{
				if(length > 20 - loc[0])  
				{
					cout<<"Error"<<endl;
					continue;
				}
				if(pen)
				{
					int i;
					for(i = loc[0];i - loc[0] + 1 <= length; i++)
					{
						floor[i][loc[1]] = true;
					}
					loc[0] = --i;
				}
				else loc[0] = loc[0] + length - 1;
			}
			else if(d == 'l')
			{
				if(length > loc[1] + 1) 
				{
					cout<<"Error"<<endl;
					continue;
				}
				if(pen)
				{
					int i;
					for(i = loc[1]; loc[1] - i + 1 <= length; i--)
					{
						floor[loc[0]][i] = true;
					}
					loc[1] = ++i;
				}
				else loc[1] = loc[1] - length + 1;
			}
		}
		else if(command == 6)
		{
			for(int i = 0; i < 20; i++)
			{
				for(int j = 0; j < 20; j++)
				{
					cout<<floor[i][j]<<' ';
				}
				cout<<endl;
			}
		}

	}

}
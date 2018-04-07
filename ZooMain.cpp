#include<iostream>
#include"zoo.h"
using namespace std;

int main()
{
	Zoo zoo(4000,50,10000,20,7000,30);
	while(zoo.Judge_StateofZoo())
	{
		zoo.Simulate_One_Day();
	}
	system("pause");
}
#include<iostream>
#include<string>
using namespace std;

struct Node
{
	string Comment;
	Node *next;
};

class LinkList
{
public:
	LinkList();		//读取文件来
	~LinkList();
	void CreateHead();
	void Insert(string NewComment);
	void Delete(int pos);
	void ShowAll();
	int Length();
	void Reverse();
};

class View_Spot
{
public:
	View_Spot();
	~View_Spot();
	void Show_Info();
	int Return_Price();
	string Return_Opendays();
	string Return_Name();
	void TouristAddTips();
	void ChangeTags();
	void Show_Comment();
private:
	string Name;
	string Opendays;
	int Price;
	string Introduction;
	LinkList Tag_List;
	LinkList Tips_List;
	const int location[2];
};

class bus
{
public:
	bus(string number,int *);	//初始化地图矩阵 在路线上画出相对应的路线
	~bus();

private:
	void Init_route(string number);
	int price;
};

class Recommand_System
{

};

class 


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
	LinkList();		//��ȡ�ļ���
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
	bus(string number,int *);	//��ʼ����ͼ���� ��·���ϻ������Ӧ��·��
	~bus();

private:
	void Init_route(string number);
	int price;
};

class Recommand_System
{

};

class 


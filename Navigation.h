//
//  Navigation.h
//  Navigation
//
//  Created by Justin Timberlake on 2018/4/26.
//  Copyright © 2018年 Justin Timberlake. All rights reserved.
//

#ifndef Navigation_h
#define Navigation_h


#include<iostream>
#include<string>
using namespace std;

struct Node
{
    string content;
    Node *next;
};

class LinkList
{
public:
    LinkList();        //读取文件来
    ~LinkList();
    void Insert(string);
    void Delete(int);
    void ShowAll();
    int Return_Length();
    Node* Reverse();
    bool Check(string);
private:
    Node * head;
    int length;
};


class Spot
{
public:
    Spot(int,int);
    virtual ~Spot() = 0;
    virtual void Show() = 0;
    string Return_Name();
    void Set_ID(string);
private:
    string id;
    const int locX;
    const int locY;
};

class Bus_Spot : public Spot
{
public:
    Bus_Spot(string,bool,int,int);
    ~Bus_Spot();
    void Show();        //business doubt
    string Get_Name();
    bool Check_Bus_Pass(string);
    void Add_Passing_Bus(string);
    
private:
    bool Station_Flag;
    LinkList Bus_LList;
};

class Bus_Route
{
public:
    Bus_Route();
    ~Bus_Route();
    
private:
    Bus_Spot Pass_Point;
};

class View_Spot : public Spot
{
public:
    View_Spot();
    ~View_Spot();
    string Return_Info();
    string Return_Name();
    string Return_Tips();
    
};

class Bus
{
public:
    Bus(string number,int *);    //初始化地图矩阵 在路线上画出相对应的路线
    ~Bus();
    void Init_route(string number);
    
private:
    int price;
    string Bus_Num;
    Bus_Route Route;
};

class Recommand_System
{

    
};










#endif /* Navigation_h */

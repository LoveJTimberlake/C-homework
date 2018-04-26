//
//  Navigation.cpp
//  Navigation
//
//  Created by Justin Timberlake on 2018/4/26.
//  Copyright © 2018年 Justin Timberlake. All rights reserved.
//

#include <stdio.h>
#include<iostream>
#include "Navigation.h"

using namespace std;

LinkList::LinkList()
{
    head = NULL;
    length = 0;
}

LinkList::~LinkList()
{
    Node * p = head;
    while(head)
    {
        p = head;
        head = head->next;
        delete p;
    }
}

void LinkList::Insert(string c)
{
    Node * temp = new Node;
    temp->content = c;
    temp->next = NULL;
    if(!head)
    {
        head = temp;
        length ++;
    }
    else
    {
        Node * p = new Node;
        p = head;
        while(p->next)
        {
            p = p->next;
        }
        p->next = temp;
        length++;
    }
}

void LinkList::Delete(int pos)
{
    if(pos > length || pos <= 0)
    {
        cout<<"Wrong Opearation"<<endl;
        return;
    }
    else if(length==1)
    {
        head = NULL;
        length--;
    }
    else if(pos == 1 && length > 1)
    {
        Node * temp = new Node;
        temp = head;
        head = head->next;
        delete temp;
        temp = NULL;
        length--;
    }
    else
    {
        Node * pre = new Node;
        pre = head;
        for (int i = 1; i != pos-1;i++)
        {
            pre = pre->next;
        }
        Node * temp = new Node;
        temp = pre->next;
        pre->next = pre->next->next;
        delete temp;
        temp = NULL;
        length--;
    }
}

void LinkList::ShowAll()
{
    if(!length)
    {
        cout<<"No Content in it"<<endl;
        return;
    }
    else
    {
        Node * p = new Node;
        p = head;
        while(p)
        {
            cout<<p->content<<endl;
            p = p->next;
        }
    }
}

int LinkList::Return_Length()
{
    return length;
}

Node* LinkList::Reverse()
{
    Node * null_head = new Node;
    Node * temp = new Node;
    Node * Second = new Node;
    Second = NULL;
    null_head->next = Second;
    temp = head;
    while(temp)
    {
        string s = temp->content;
        Node * ins = new Node;
        ins->content = s;
        null_head->next = ins;
        ins->next = Second;
        Second = ins;
    }
    
    return null_head->next;
}

bool LinkList::Check(string c)
{
    Node * p = new Node;
    p = head;
    while(p)
    {
        if(p->content == c) return true;
        else p = p->next;
    }
    return false;
}

Spot::Spot(int x,int y):locX(x),locY(y)
{
}

void Spot::Set_ID(string ID)
{
    id = ID;
}

string Spot::Return_Name()
{
    return id;
}

Bus_Spot::Bus_Spot(string bus_num,bool flag,int x,int y):Spot(x,y)
{
    Set_ID(bus_num);
    if(flag) Station_Flag = true;
    else Station_Flag = false;
}

string Bus_Spot::Get_Name()
{
    return Return_Name();
}

void Bus_Spot::Add_Passing_Bus(string bus_num)
{
    Bus_LList.Insert(bus_num);
}

bool Bus_Spot::Check_Bus_Pass(string bus_num)
{
    return Bus_LList.Check(bus_num);
}

















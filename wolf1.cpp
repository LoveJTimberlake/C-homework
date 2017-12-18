#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<iostream>
#define OK 1
#define ERROR 0
#define OVERFLOW 0
#define INIT 0
#define VISIT 1
using namespace std;


typedef struct CLNode
{
 int data;
 struct CLNode *next;
}CLNode, *CLinkList;


int InitList_CL(CLinkList &L)
{
 L = (CLinkList) malloc(sizeof(CLNode));
 if(!L)
  exit(OVERFLOW);
 L->data=INIT;
 L->next = L;
 return OK;
}



int CreateList_CL(CLinkList &L, int n)
{
 CLinkList p, q;
 int i;

 //p = (CLinkList) malloc(sizeof(CLNode));
 q = L;
 for(i=0;i<n-1;i++)
 {
  p = (CLinkList) malloc(sizeof(CLNode));
  if(!p) return ERROR;
  q->next=p;
  p->next=L;
  p->data=INIT;
  q=p;
 }

 return OK;
}



int GetElem_CL(CLinkList L, int i)
{
 CLinkList p;
 int j=1;
 p = L;
 while(j<i)
 {
 p = p->next;
 ++j;
 }
 p->data = VISIT;
 return OK;
}



int TravseList_CL(CLinkList L)
{
 CLinkList p;
 p = L;
 int i = 1;
 do 
 {
 if(!p->data) cout<<i<<' ';
 p = p->next;
 i++;
 } while(p!=L);
 return OK;
}



void main ()
{
 CLinkList L;
 int i,n,t;
 cin>>n;
 InitList_CL(L);
 CreateList_CL(L,n);
 

 for(i=0, t=1;t<n+1;t++)
  {
  i=i+t;
  GetElem_CL(L, i);
  }
 printf("Hole:");
 TravseList_CL(L);
 system("pause");
}
   
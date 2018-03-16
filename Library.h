#include<iostream>
#include<string.h>
using namespace std;

class BookRecord
{
public:
    friend class Catalogue;
    friend class Library;
    string book_id(BookRecord & BR);		//返回书籍id
    void Print_Record();    //输出所有记录
    BookRecord();			
	~BookRecord(){};
    
private:
    string ID;
    string title;
    string name;
    string year;
    string num_all_copies;
    string num_free_cpoies;
    
};


class BorrowerRecord
{
public:
    friend class Library;
    BorrowerRecord();
	~BorrowerRecord(){};
    void Print_Record();
    
private:
    string ID;
    string name;
    string num_book_loan_person;	//读者一个人借的书数目
    string *Book_List_Loan;    //读者记录中记录其借了什么书的列表
    
};


class Catalogue
{
public:
    Catalogue(Library &L);
	~Catalogue(){};
    void Print_num_book_Catalogue(Library & L);		//free_book之和
    void Print_book_records(Library & L);			//所有书籍的信息,调用的是bookrecord类的输出函数
    
private:
    int num_book_record;							//共有多少个书籍信息的数目
    BookRecord *BookRecords;						//一个记录书籍信息的数组
    
};



class Library
{
private:
	int kinds_book;					//书的总种类数目，用于初始化book_list,可从输入直接获得
	int all_book_loan_num;			//共借出了多少书籍,要初始化为0
	int all_book_num;				//记录一开始共有多少本书，从bookrecord中逐一提取。并在最后减去loan_num得到catalogue中书的数量。
    int number_borrowers;			//由输入数据直接而得
	BookRecord * book_list;			//用于保存所有的书的数组用于输出书籍信息
	BorrowerRecord * BorrowerR;		//用于保存所有读者记录

public:
	friend class Catalogue;
    Library();						//初始化一个BorrowerR对象数组和一个已有书籍信息对象的数组，并生成catalogue对象
    ~Library();
    void Print_num_book_loan();     //输出all_book_loan_num
    void Print_num_book_free();		//输出all_book_num - all_book_loan_num
    void Print_num_Borrowers();		//输出number_borrowers
    void Print_All_Borrowers();     //调用borrowers类中的输出函数
	void Cal_Book_Loan_Num();		//计算共被借走了多少书
	void Cal_Book_All_Num();		//计算共有多少本书
	void PerBook_FreeNum();			//计算每本书还剩多少本空余
};
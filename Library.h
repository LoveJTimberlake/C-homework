#include<iostream>
#include<string.h>
using namespace std;

class BookRecord
{
public:
    friend class Catalogue;
    friend class Library;
    string book_id(BookRecord & BR);		//�����鼮id
    void Print_Record();    //������м�¼
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
    string num_book_loan_person;	//����һ���˽������Ŀ
    string *Book_List_Loan;    //���߼�¼�м�¼�����ʲô����б�
    
};


class Catalogue
{
public:
    Catalogue(Library &L);
	~Catalogue(){};
    void Print_num_book_Catalogue(Library & L);		//free_book֮��
    void Print_book_records(Library & L);			//�����鼮����Ϣ,���õ���bookrecord����������
    
private:
    int num_book_record;							//���ж��ٸ��鼮��Ϣ����Ŀ
    BookRecord *BookRecords;						//һ����¼�鼮��Ϣ������
    
};



class Library
{
private:
	int kinds_book;					//�����������Ŀ�����ڳ�ʼ��book_list,�ɴ�����ֱ�ӻ��
	int all_book_loan_num;			//������˶����鼮,Ҫ��ʼ��Ϊ0
	int all_book_num;				//��¼һ��ʼ���ж��ٱ��飬��bookrecord����һ��ȡ����������ȥloan_num�õ�catalogue�����������
    int number_borrowers;			//����������ֱ�Ӷ���
	BookRecord * book_list;			//���ڱ������е����������������鼮��Ϣ
	BorrowerRecord * BorrowerR;		//���ڱ������ж��߼�¼

public:
	friend class Catalogue;
    Library();						//��ʼ��һ��BorrowerR���������һ�������鼮��Ϣ��������飬������catalogue����
    ~Library();
    void Print_num_book_loan();     //���all_book_loan_num
    void Print_num_book_free();		//���all_book_num - all_book_loan_num
    void Print_num_Borrowers();		//���number_borrowers
    void Print_All_Borrowers();     //����borrowers���е��������
	void Cal_Book_Loan_Num();		//���㹲�������˶�����
	void Cal_Book_All_Num();		//���㹲�ж��ٱ���
	void PerBook_FreeNum();			//����ÿ���黹ʣ���ٱ�����
};
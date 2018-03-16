#include<iostream>
#include<string>
#include"Library.h"
#include<stdlib.h>
using namespace std;


BookRecord::BookRecord()   //读取输入的字符串抽取分号读取信息填入对象中同时检查信息
{
    string s;
    getline(cin,s);
	int i,j,n,counter = 0;
	n = s.length();
    for(i = 0,j = 0; i < n;i++)
	{
		if(s[i] == ';')
		{
			switch(counter)
			{
				case 0: 
					{
						this->ID = s.substr(j,i-j);
						if(!((this->ID)[0] >= 'A' && (this->ID)[0] <= 'Z')) 
						{
							cout<<"Your ID is wrong!";
							system("pause");
							exit(1);
						}
						break;
					}
				case 1:
					{
						this->title = s.substr(j,i-j);
						break;
					}
				case 2:
					{
						this->name = s.substr(j,i-j);
						break;
					}
				case 3:
					{
						this->year = s.substr(j,i-j);
						if(((year).length() != 4)|| ((year)[0] != '1'&&(year)[0] != '2'))
						{
							cout<<"Your book's year is wrong";
							system("pause");
							exit(1);
						}
						break;
					}
			}
			j = i+1;
			if(j == n-1) 
				{
					this->num_all_copies = s.substr(j,1);
					this->num_free_cpoies = this->num_all_copies;
					break;
				}
			counter++;
		}
	}
}


string BookRecord::book_id(BookRecord & BR)
{
    return BR.ID;
}


void BookRecord::Print_Record()
{
    cout<<"=========="<<endl;
    cout<<"Book ID:"<<' '<<this->ID<<endl;
    cout<<"Title:"<<' '<<this->title<<endl;
    cout<<"Author:"<<' '<<this->name<<endl;
    cout<<"Year published:"<<' '<<this->year<<endl;
    cout<<"Total number of copies:"<<' '<<this->num_all_copies<<endl;
    cout<<"Number available for loan:"<<' '<<this->num_free_cpoies<<endl;
	cout<<endl<<endl;
}

void BorrowerRecord::Print_Record()
{
	cout<<"=========="<<endl;
	cout<<"Borrower ID:"<<' '<<this->ID<<endl;
	cout<<"Name: "<<this->name<<endl;
	cout<<"Number of loaned books: "<<this->num_book_loan_person<<endl;
	cout<<"IDs of books on loan: ";
	for(int i = 0; i < atoi((this->num_book_loan_person).c_str()); i++)
	{
		cout<<this->Book_List_Loan[i]<<' ';
	}
	cout<<endl<<endl;
}

BorrowerRecord::BorrowerRecord()
{
	string s;
	getline(cin,s);
	int i,j,m = 0,counter = 0;
	for(i = 0,j = 0; i<s.length();i++)
	{
		if(s[i] == ';')
		{
			switch(counter)
			{
				case 0:
					{
						this->ID=s.substr(j,i-j);
						if((this->ID).length() != 5)	
						{
							cout<<"Reader's ID is wrong";
							system("pause");
							exit(1);
						}
						break;
					}
				case 1:
					{
						this->name = s.substr(j,i-j);
						break;
					}
				case 2:
					{
						this->num_book_loan_person = s.substr(j,i-j);
						this->Book_List_Loan  = new string [atoi(this->num_book_loan_person.c_str())];
						break;
					}
				case 3:
				case 4:
				case 5:
				case 6:
					{
						this->Book_List_Loan[m++] = s.substr(j,i-j);
						break;
					}
			}
			counter++;
			j = i+1;
			if(j == s.length()-4)
			{
				this->Book_List_Loan[m] = s.substr(j,i-j);
				break;
			}
		}
	}
}


Library::Library()
{
	all_book_loan_num = 0;
	all_book_num = 0;
	cin>>kinds_book;
	book_list = new BookRecord [kinds_book+1];
	cout<<"初始化书籍完成"<<endl;
	cin>>number_borrowers;
	BorrowerR = new BorrowerRecord [number_borrowers+1];
	Cal_Book_All_Num();
	Cal_Book_Loan_Num();
	PerBook_FreeNum();
	cout<<"初始化读者完成"<<endl;
}

void Library::Print_num_book_loan()
{
	cout<<"Total number of books on loan: "<<all_book_loan_num<<endl;
}

void Library::Print_num_Borrowers()
{
	cout<<"Number of Borrowers:" <<number_borrowers<<endl;
}

void Library::Print_num_book_free()
{
	cout<<"Total number of books in catalogue:"<<all_book_num - all_book_loan_num<<endl;
}

void Library::Print_All_Borrowers()
{
	for(int i = 1; i < number_borrowers+1; i++)
	{
		cout<<"Borrower"<<' '<<i<<':'<<endl;
		BorrowerR[i].Print_Record();
	}
}

void Library::Cal_Book_All_Num()
{
	for(int i = 1; i < kinds_book+1; i++)
	{
		all_book_num += atoi(book_list[i].num_all_copies.c_str());
	}
}

void Library::Cal_Book_Loan_Num()
{
	for(int i = 1; i < number_borrowers+1; i++)
	{
		all_book_loan_num += atoi(BorrowerR[i].num_book_loan_person.c_str());
	}
}

void Library::PerBook_FreeNum()
{
	for(int i = 1; i < number_borrowers+1; i++)
	{
		for(int j  = 0; j < atoi(BorrowerR[i].num_book_loan_person.c_str());j++)
		{
			string Checked_Book_ID = (BorrowerR[i].Book_List_Loan)[j];
			for(int s = 1; s < kinds_book+1;s++)
			{
				if(book_list[s].ID == Checked_Book_ID) 
				{
					int m = atoi(book_list[s].num_free_cpoies.c_str());
					m--;
					char t[20];
					itoa(m,t,10);
					book_list[s].num_free_cpoies = t;
				}
			}
		}
	}
}

Library::~Library()
{
	delete []book_list;
	delete []BorrowerR;
	BorrowerR = NULL;
	book_list = NULL;
}

Catalogue::Catalogue(Library &L)
{
	BookRecords = L.book_list;
	num_book_record = L.kinds_book;
}

void Catalogue::Print_num_book_Catalogue(Library &L)
{
	cout<<"Total number of books in catalogue:"<<L.all_book_num - L.all_book_loan_num<<endl;
}

void Catalogue::Print_book_records(Library &L)
{
	for(int i = 1; i < L.kinds_book+1; i++)
	{
		cout<<"BookRecord"<<' '<<i<<':'<<endl;
		(L.book_list[i]).Print_Record();
	}
}
	
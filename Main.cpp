#include<iostream>
#include"Library.h"
using namespace std;

int main()
{
	Library L;
	Catalogue C(L);
	L.Print_num_book_loan();
	C.Print_num_book_Catalogue(L);
	cout<<endl<<endl<<endl;
	C.Print_book_records(L);
	L.Print_All_Borrowers();
	system("pause");
}
#include<iostream>

using namespace std;

double tax(double m)

{ 
	if( m <= 1200) return 0;
	else if(m <=2200) return 0.05*(m-1200);
	else if(m <= 4200) return 0.1*(m-1200);
	else if(m <= 6200) return 0.15*(m-1200);
	else if(m <=11200) return 0.2*(m-1200);
	else return 0.3*(m-1200);
}




int main()

{ 

    double income, j = 0; 

    cout << "��������������룺" << endl; 

     cin >> income;

     j = tax(income); 

    cout << "Ӧ������˰��" << j << endl; 

    system("pause"); 

    return 0;

}

#include<iostream>
using namespace std;

class Matrix
{
public:
	Matrix();
	~Matrix();
	Matrix& operator+(const Matrix& M);
	Matrix& operator-(const Matrix& M);
	Matrix& operator*(const Matrix& M);
	Matrix& operator+=(const Matrix& M);
	Matrix& operator-=(const Matrix& M);
	Matrix& operator*=(const Matrix& M);
	Matrix& operator*(int i);
	bool operator==(const Matrix& M);
	bool operator!=(const Matrix& M);
	friend ostream& operator<<(ostream & os, const Matrix& M);
	friend istream& operator>>(istream & is, const Matrix& M);
	int **num;
};
#include<iostream>
using namespace std;
#include"Matrix.h"

Matrix::Matrix()
{
	num  = new int *[2];
	for(int i = 0; i < 2;i++)
	{
		num[i] = new int [2];
		for(int j = 0; j < 2; j++)
		{
			if((i+j)%2) num[i][j] = 0;
			else num[i][j] = 1;
		}
	}
}

Matrix::~Matrix()
{
	for(int i = 0; i < 2; i++)
		delete[] num[i];
	num = NULL;
}

Matrix& Matrix::operator+(const Matrix& M)
{
	Matrix &_M = *this;
	for(int i = 0; i < 2; i++)
	{
		for(int j = 0; j < 2; j++)
			_M.num[i][j] = this->num[i][j] + M.num[i][j];
	}
	return _M;
}

Matrix& Matrix::operator-(const Matrix& M)
{
	Matrix & _M = *this;
	for(int i = 0; i < 2; i++)
	{
		for(int j = 0; j < 2; j++)
			_M.num[i][j] = this->num[i][j] - M.num[i][j];
	}
	return _M;
}

Matrix& Matrix::operator*(const Matrix& M)
{
	Matrix & _M = *this;
	for(int i = 0; i < 2; i++)
	{
		for(int j = 0; j < 2; j++)
			_M.num[i][j] = this->num[i][0] * M.num[0][j] + this->num[i][1] * M.num[1][j];
	}
	return _M;
}

Matrix& Matrix::operator+=(const Matrix& M)
{
	Matrix & _M = *this;
	for(int i = 0; i < 2; i++)
	{
		for(int j = 0; j < 2; j++)
			_M.num[i][j] = this->num[i][j] + M.num[i][j];
	}
	return _M;
}

Matrix& Matrix::operator-=(const Matrix& M)
{
	Matrix & _M = *this;
	for(int i = 0; i < 2; i++)
	{
		for(int j = 0; j < 2; j++)
			_M.num[i][j] = this->num[i][j] - M.num[i][j];
	}
	return _M;
}

Matrix& Matrix::operator*=(const Matrix& M)
{
	Matrix & _M = *this;
	for(int i = 0; i < 2; i++)
	{
		for(int j = 0; j < 2; j++)
			_M.num[i][j] = this->num[i][0] * M.num[0][j] + this->num[i][1] * M.num[1][j];
	}
	return _M;
}

Matrix& Matrix ::operator*(int s)
{
	Matrix & _M = *this;
	for(int i = 0; i < 2; i++)
	{
		for(int j = 0; j < 2; j++)	
			_M.num[i][j] = _M.num[i][j] * s;
	}
	return _M;
}

Matrix& operator*(int s,Matrix &M)
{
	return M * s;
}

bool Matrix::operator==(const Matrix& M)
{
	for(int i = 0; i < 2; i++)
	{
		for(int j = 0; j < 2; j++)
		{
			if(M.num[i][j] != this->num[i][j]) return false;
		}
	}
	return true;
}

bool Matrix::operator!=(const Matrix& M)
{
	return !(*this == M);
}


istream& operator>>(istream& is, const Matrix& M)
{
	for(int i = 0; i < 2; i++)
	{
		for(int j = 0; j < 2; j++)
			is>>M.num[i][j];
	}
	return is;
}

ostream& operator<<(ostream& os, const Matrix& M)
{
	for(int i = 0; i < 2; i++)
	{
		for(int j = 0; j < 2; j++)
			os<<M.num[i][j]<<' ';
		cout<<endl;
	}
	return os;
}

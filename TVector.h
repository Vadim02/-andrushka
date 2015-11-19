#include <iostream>
#include <math.h>
#include <conio.h>   
#include <fstream>
#include <iostream>
#include <math.h>
#include <float.h> 
#include <time.h> 

#ifndef _TVECTOR
#define _TVECTOR
using namespace std;

static char* Err_zero = "�������� ������� �� ����  !!!!!!!!!";
static char* Err_lim = "������� ������� ������� �� �������� INT!!!";
static char* cont = " \n \n    ������� ����� ������� - �����������    ��� ESC - ����� .....\n";
static char* Err_equal = " ������� �� ��������!!!!";

class TVector {

private:

	int vec_size;
	int *vec;
	char* name;

public:

	friend int Show(int sizea, int sizeb, int sizex);
	friend void Res(int sizea, int sizeb, int sizex);
	friend istream &operator >>(istream &input, TVector &a);
	friend ostream &operator <<(ostream &output, TVector &a);

	TVector operator +(TVector &b);
	TVector operator +(int b);

	TVector operator -(TVector &b);
	TVector operator -(int b);
	TVector operator /(TVector &b);
	TVector operator *(int b);
	TVector operator *(TVector &b);

	TVector operator -();
	TVector operator =(TVector &b);
	TVector operator =(const int b);
	int operator [](const int i);

	bool operator >(const TVector &a);
	bool operator <(const TVector &a);
	bool operator ==(const TVector &a);

	TVector(int size, char* a);
	TVector(const TVector &init);

	void rand_vec(int i);
	TVector();
	~TVector();
};
#endif
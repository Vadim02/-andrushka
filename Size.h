#include <fstream>
#include <iostream>
#include <math.h>
#include <float.h> 
#include <typeinfo.h> 
using namespace std;

int input(int &k, char* vec)
{
	cout << "������� ������ ������� " << vec << " � ��������� �� 1 �� 1000 -> ";
	cin >> k;
	
	if (cin.fail() || cin.bad() || k < 1 || k > 1000)
	{
		cout << "������ ����� ��������! ��������� ����!\n";
		cin.sync();
		cin.clear();
		return 1;
	}
	return 0;
}

void Size(int &k, char* vec)
{
	while (input(k, vec));
	cout << endl;
}

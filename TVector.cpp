#include "TVector.h"
using namespace std;

TVector::TVector(int size, char* a)
{
#ifdef _DEBUG
	cout << "========= Создаю данные-члены класса для массива " << a << endl;
#endif
	name = a;
	vec_size = size;
	vec = new int[vec_size];
	for (int i = 0; i < vec_size; i++)
	{
		vec[i] = i;
	}
}

TVector::TVector()
{
	vec_size = 0;
	vec = 0;
}
TVector::TVector(const TVector &init) {
	vec_size = init.vec_size;
	vec = new int[vec_size];
#ifdef _DEBUG
	name = init.name;
#endif
	_ASSERT(vec != 0);
	for (int i = 0; i < vec_size; i++) {
		vec[i] = init.vec[i];
	}
}
//===========================================================================
istream &operator >>(istream &input, TVector &a)
{
	bool pr = true;
	for (int i = 0; i < a.vec_size; i++)
	{
		do
		{
			cout << a.name << "[" << i << "] -> ";
			input >> a.vec[i];
			if ((input.bad()) || (input.fail()))
			{
				pr = true;
				cout << "Ошибка ввода символов!\n";
				cout << "Повторите ввод -> \n";
				input.sync();
				input.clear();
			}
			else
			{
				pr = false;
			}
		} while (pr);
	}
	return input;
}

ostream &operator <<(ostream &output, TVector &a)
{
	for (int i = 0; i < a.vec_size; i++)
		output << "[" << i << "] = " << a.vec[i] << endl;
	output << endl;
	return output;
}
//===========================================================================
int TVector :: operator [](const int i) {

	return vec[i];
}

TVector TVector :: operator -() {
	for (int i = 0; i < vec_size; i++) {
		vec[i] = -vec[i];
	}
	return *this;
}
//===========================================================================
bool TVector :: operator >(const TVector &b) {
	TVector x(*this);
	if (x.vec_size != b.vec_size) return (x.vec_size > b.vec_size);

	else {
		int sumb = 0, sumx = 0, prb = 0, prx = 0;
		for (int i = 0; i < x.vec_size; i++) {
			sumb += b.vec[i];
			sumx += x.vec[i];
			if (b.vec[i] > x.vec[i]) prb++;
			if (b.vec[i] < x.vec[i]) prx++;
		}
		if (sumb != sumx) return (sumx > sumb);
		else {
			if (prx != prb) return (prx > prb);
			else return false;
		}
	}
}

bool TVector :: operator ==(const TVector &b) {
	TVector x(*this);
	if (x.vec_size == b.vec_size) {

		for (int i = 0; i < vec_size; i++) {
			if (x.vec[i] != b.vec[i]) return false;
		}
		return true;
	}
	else return false;
}
//===========================================================================
TVector TVector ::  operator +(TVector &b) {
	int size;
	TVector x(*this);
	if (vec_size < b.vec_size) size = vec_size;
	else size = b.vec_size;
	for (int i = 0; i < size; i++) {
		x.vec[i] += b.vec[i];
		if ((x.vec[i] > INT_MAX) || (x.vec[i] < INT_MIN)) throw Err_lim;
	}
	return x;
}

TVector TVector ::  operator +(const int b) {
	TVector x(*this);
	for (int i = 0; i < x.vec_size; i++) {
		x.vec[i] += b;
		if ((x.vec[i] > INT_MAX) || (x.vec[i] < INT_MIN)) throw Err_lim;
	}
	return x;
}
//===========================================================================
TVector TVector ::  operator -(TVector &b) {
	int size;
	TVector x(*this);
	if (vec_size < b.vec_size) size = vec_size;
	else size = b.vec_size;
	for (int i = 0; i < size; i++) {
		x.vec[i] -= b.vec[i];
		if ((x.vec[i] > INT_MAX) || (x.vec[i] < INT_MIN)) throw Err_lim;
	}
	return x;
}

TVector TVector ::  operator -(const int b) {
	TVector x(*this);
	for (int i = 0; i < x.vec_size; i++) {
		x.vec[i] -= b;
		if ((x.vec[i] > INT_MAX) || (x.vec[i] < INT_MIN)) throw Err_lim;
	}
	return x;
}
//===========================================================================
TVector TVector ::  operator /(TVector &b) {
	int size;
	TVector x(*this);
	if (vec_size < b.vec_size) size = vec_size;
	else size = b.vec_size;
	for (int i = 0; i < size; i++) {
		if (b.vec[i] == 0) throw Err_zero;
		x.vec[i] /= b.vec[i];
	}
	return x;
}
//===========================================================================
/*TVector TVector :: operator *(TVector &b){
int size=0;
TVector x(*this);
for(int i=0;i<size;i++)
{
x.vec[i] *= b.vec[i];
}
return x;
}*/

TVector TVector :: operator *(const int b) {
	int size;	
	TVector x(*this);
	if (vec_size < b) size = vec_size;
	else size = b;
	for (int i = 0;i<size;i++)
	{
		x.vec[i] *= b;
	}
	return x;
}
//===========================================================================
TVector TVector :: operator =(TVector &b) {
	int size;
	if (&b != this)
	{
		if (vec_size < b.vec_size) size = vec_size;
		else size = b.vec_size;
		/*	if (name != "X"){
		delete [] vec;
		vec_size = b.vec_size;
		vec = new int [vec_size];
		}*/
		for (int i = 0; i < size; i++)
		{
			vec[i] = b.vec[i];
		}
		for (int i = size; i < vec_size; i++)
		{
			vec[i] = -99999999;
		}
	}
	return *this;
}

TVector TVector :: operator =(const int b) {
	delete[] vec;

	vec_size = 1;
	vec = new int[vec_size];

	vec[0] = b;
	return *this;
}
//===========================================================================
void Res(int sizea, int sizeb, int sizex) {

	TVector A(sizea, "A");
	TVector B(sizeb, "B");
	TVector X(sizex, "X");

	if (A.vec_size > 10) A.rand_vec(5);
	else {
		cout << "Введите массив A:\n";
		cin >> A;
	}
	if (B.vec_size > 10) B.rand_vec(10);
	else {
		cout << "Введите массив B:\n";
		cin >> B;
	}
	cout << "Массив A:\n" << A;
	cout << "Массив B:\n" << B;

	if ((sizex > sizeb) || (sizex > sizea))  cout << "Размер массива Х больше А и В, значения не заполненных ячеек будут равны -99999999 " << endl;

	if (A > B) {
		cout << "A > B -> X = A / B + 11" << endl;
		X = A / B + 11;
		cout << "Массив X: \n" << X;
	}
	if (A == B) {
		cout << "A == B -> X = -11 " << endl;
		X = -11;
		cout << "Массив X:\n" << X;
	}
	if (B > A) {
		cout << "A < B -> X = (3 * B - 9) / A" << endl;
		X = ((B * 3) - 9) / A;
		cout << "Массив X:\n" << X;
	}
	if (!(A > B) && !(A == B) && !(B > A)) {
		cout << "Массивы невозможно сравнить: они и не равны, и нe больше/меньше друг друга" << endl;
		cout << "Для выхода из программы нажмите Esc\n";
	}
}

int Show(int sizea, int sizeb, int sizex) {

	try {
		Res(sizea, sizeb, sizex);
		cout << cont;
	}
	catch (char* v) {
		cout << "\n!!!!! Обработка исключительной ситуации. !!!!!" << endl;
		cout << "Ошибка: " << v << endl;
		cout << cont << endl;
	}
	catch (...) {
		cout << "\n!!!!! Обработка незапланированной исключительной ситуации." << endl;
		cout << cont << endl;
		throw; // ? 
	}
	return (_getch());
}

void TVector::rand_vec(int k) {
	srand((unsigned)time(NULL));
	for (int i = 0; i < vec_size; i++)
		vec[i] = rand() % k + rand() % vec_size - rand() % vec_size;
}
TVector :: ~TVector()
{
#ifdef _DEBUG
	cout << "~~~~~~~~~~Уничтожаю данные-члены класса класса для массива " << name << " ~~~~~~~~~~" << endl;
#endif
	delete[] vec;
}

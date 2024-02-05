#include"testoperator.h"

const Complex operator+(const Complex& L, const Complex& R)
{
	Complex temp;
	temp.real = L.real + R.real;
	temp.vir = L.vir + R.vir;
	return temp;
}

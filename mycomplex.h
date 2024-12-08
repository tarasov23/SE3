/*!
	@file
	@brief Заголовочный файл класса Complex
*/

#ifndef _MY_COMPLEX_H_
#define _MY_COMPLEX_H_
#include <iostream>

using namespace std;

/*!
	@brief Класс комплексного числа Complex
*/

class Complex
{
	/*!
		@brief Действительная часть числа
	*/
	double Re;

	/*!
		@brief Мнимая часть числа
	*/
	double Im;

public:
	Complex(double Real = 0, double Imaginary = 0);

	Complex(const Complex&);

	~Complex();

	void Set(double Real, double Imaginary = 0);

	operator double();

	double abs();

	friend istream& operator>> (istream&, Complex&);

	friend ostream& operator<< (ostream&, Complex&);

	Complex operator+ (const Complex&);

	Complex operator- (const Complex&);

	Complex operator+ (const double&);

	friend Complex operator+ (const double&, const Complex&);

	Complex operator- (const double&);

	friend Complex operator- (const double&, const Complex&);

	Complex operator* (const Complex&);

	Complex operator* (const double&);

	friend Complex operator* (const double&, const Complex&); 

	Complex operator/ (const double&);

	Complex& operator+= (const Complex&);

	Complex& operator-= (const Complex&);

	Complex& operator*= (const Complex&);  

	Complex& operator+= (const double&);

	Complex& operator-= (const double&);

	Complex& operator*= (const double&);

	Complex& operator/= (const double&);

	Complex& operator= (const Complex&);

	Complex& operator= (const double&);
};
#endif

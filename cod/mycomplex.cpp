#include <iostream>
#include <cmath>
#include "mycomplex.h"

using namespace std;

/*!
	@brief Конструктор класса Complex с задачей в него действительной и мнимой частей
*/
Complex::Complex(double Real, double Imaginary)
{
	Re = Real;
	Im = Imaginary;
}

/*!
	@brief Конструктор класса Complex с задачей в него одинаковой действительной и мнимой частей
*/
Complex::Complex(const Complex& aRval)
{
	Re = aRval.Re;
	Im = aRval.Im;
}

/*!
	@brief Деструктор класса Complex, т.е. обнуление действительной и мнимой частей
*/
Complex::~Complex()
{
	Re = 0.0;
	Im = 0.0;
}

void Complex::Set(double Real, double Imaginary)
{
	Re = Real;
	Im = Imaginary;
}

/*!
	@brief метод класса Complex, возвращающий модуль комплексного числа
*/
Complex::operator double()
{
	return abs();
}

/*!
	@brief метод класса Complex, вычисляющий модуль комплексного числа
*/
double Complex::abs()
{
	return sqrt(Re * Re + Im * Im);
}

/*!
	@brief метод класса Complex, вычисляющий сумму изначального комплексного числа и заданного комплексного числа
*/
Complex Complex::operator+ (const Complex& aRval)
{
	Complex Result;
	Result.Re = Re + aRval.Re;
	Result.Im = Im + aRval.Im;
	return Result;
}

/*!
	@brief метод класса Complex, вычисляющий разность изначального комплексного числа и заданного комплексного числа
*/
Complex Complex::operator- (const Complex& aRval)
{
	Complex Result;
	Result.Re = Re - aRval.Re;
	Result.Im = Im - aRval.Im;
	return Result;
}

/*!
	@brief метод класса Complex, увеличивающий реальную часть комплексного числа
*/
Complex Complex::operator+ (const double& aLval)
{
	Complex Result;
	Result.Re = Re + aLval;
	Result.Im = Im;
	return Result;
}

/*!
	@brief метод класса Complex, уменьшающий реальную часть комплексного числа
*/
Complex Complex::operator- (const  double& aRval)
{
	Complex Result(*this);
	Result.Re = Re - aRval;
	return Result;
}

/*!
	@brief метод класса Complex, умножающий изначальное комплексное число на заданное комплексное число
*/
Complex Complex::operator* (const Complex& aRval)
{
	Complex Result;
	Result.Re = Re * aRval.Re - Im * aRval.Im;
	Result.Im = Re * aRval.Im + Im * aRval.Re;
	return Result;
}

/*!
	@brief метод класса Complex, умножающий изначальное комплексное число на константу
*/
Complex Complex::operator* (const double& aRval)
{
	Complex Result;
	Result.Re = Re * aRval;
	Result.Im = Im * aRval;
	return Result;
}

/*!
	@brief метод класса Complex, вычисляющий результат деления изначального комплексного числа на константу
*/
Complex Complex::operator/ (const double& aRval)
{
	Complex Result;
	Result.Re = Re / aRval;
	Result.Im = Im / aRval;
	return Result;
}

/*!
	@brief метод класса Complex, присваивающий комплексному числу значение суммы изначального и заданного комплексных чисел
*/
Complex& Complex::operator+= (const   Complex& aRval)
{
	Re += aRval.Re;
	Im += aRval.Im;
	return *this;
}

/*!
	@brief метод класса Complex, присваивающий комплексному числу значение разности изначального и заданного комплексных чисел
*/
Complex& Complex::operator-= (const Complex& aRval)
{
	Re -= aRval.Re;
	Im -= aRval.Im;
	return *this;
}

/*!
	@brief метод класса Complex, присваивающий комплексному числу значение произведения изначального и заданного комплексных чисел
*/
Complex& Complex::operator*= (const Complex& aRval)
{
	double tmpRe = Re;
	Re = Re * aRval.Re - Im * aRval.Im;
	Im = Im * aRval.Re + tmpRe * aRval.Im;
	return *this;
}

/*!
	@brief метод класса Complex, присваивающий реальной части комплексного числа значение суммы этой части с реальным числом
*/
Complex& Complex::operator+= (const double& aRval)
{
	Re += aRval;
	return*this;
}

/*!
	@brief метод класса Complex, присваивающий реальной части комплексного числа значение разности этой части и реального числа
*/
Complex& Complex::operator-= (const double& aRval)
{
	Re -= aRval;
	return *this;
}

/*!
	@brief метод класса Complex, присваивающий комплексному числу значение произведения изначального и заданного комплексных чисел
*/
Complex& Complex::operator*= (const  double& aRval)
{
	Re *= aRval;
	Im *= aRval;
	return *this;
}

/*!
	@brief метод класса Complex, присваивающий реальной части комплексного числа значение суммы этой части с реальным числом
*/
Complex& Complex::operator/= (const double& aRval)
{
	Re /= aRval;
	Im /= aRval;
	return *this;
}

/*!
	@brief метод класса Complex, присваивающий изначальному комплексному числу значение заданного комплексного числа
*/
Complex& Complex::operator= (const Complex& aRval)
{
	Re = aRval.Re;
	Im = aRval.Im;
	return *this;
}

/*!
	@brief метод класса Complex, превращающий комплексное число в заданное реальное
*/
Complex& Complex::operator= (const double& aRval)
{
	Re = aRval;
	Im = 0.0;
	return *this;
}

/*!
	@brief метод класса Complex, проверяющий, больше ли изначальное число заданного
*/
istream& operator>> (istream& stream, Complex& min)
{
	char tmp[256];
	stream >> min.Re >> min.Im >> tmp;
	return stream;
}

/*!
	@brief метод класса Complex, проверяющий, меньше ли изначальное число заданного
*/
ostream& operator<< (ostream& stream, Complex& max)
{
	stream << max.Re;
	if (!(max.Im < 0)) stream << '+';
	stream << max.Im << 'i';
	return stream;
}

/*!
	@brief метод класса Complex, вычисляющий сумму изначального комплексного числа и заданных комплексного и реального чисел
*/
Complex operator+ (const double& aLval, const Complex& aRval)
{
	Complex Result;
	Result.Re = aLval + aRval.Re;
	Result.Im = aRval.Im;
	return Result;
}

/*!
	@brief метод класса Complex, вычисляющий разность изначального комплексного числа и заданных комплексного и реального чисел
*/
Complex operator- (const double& aLval, const Complex& aRval)
{
	Complex Result;
	Result.Re = aLval - aRval.Re;
	Result.Im = -aRval.Im;
	return Result;
}

/*!
	@brief метод класса Complex, вычисляющий произведение изначального комплексного числа и заданных комплексного и реального чисел
*/
Complex operator* (const double& aLval, const Complex& multiplier)
{
	Complex Result;
	Result.Re = aLval * multiplier.Re;
	Result.Im = aLval * multiplier.Im;
	return Result;
}

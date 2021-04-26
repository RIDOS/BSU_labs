#include "pch.h"
#include <iostream>
#include <cmath>
#include <cstring>
#include <string>

using namespace std;

double rectangle_method(double a, double b, double n, double h, double eps);
double trapezoid_method(double a, double n, double h, double eps);
double P(double x);
double F(double x);
double dF(double x);


int main()
{
	system("chcp 1251>nul");
	double a, b, h, eps, trapezoid, S, L;
	int n;

	cout << "Численное интегрирование. { RIDOS }.\nНеобходимо ввести интервал [a,b] и количество разбиений отрезка." << endl;

	cout << "\nВведите координату A: ";
	cin >> a;
	cout << "Введите координату B: ";
	cin >> b;
	cout << "Введите количество разбиений: ";
	cin >> n;
	cout << "Введите минимальное значение (E): ";
	cin >> eps;

	h = (b - a) / n;

	L = rectangle_method(a, b, n, h, eps);
	S = P(b) - P(a);
	
	while (abs(S - L) >= eps) 
	{
		n *= 2;
	}
	L = rectangle_method(a, b, n, h, eps);

	cout << "\nМетод Ньютона Лейбница:" << S << endl;
	cout << "Метод центральных прямоугольников: " << L << endl;

	trapezoid = trapezoid_method(a, n, h, eps);
	// Для уточнения значений n
	cout << "Метод трапеций: " << trapezoid << endl;

	system("pause > nul");
}

double rectangle_method(double a, double b, double n, double h, double eps)
{
	double s = (F(a) + F(b)) / 2, I;
	for (int i = 1; i < n-1; i++)
	{
		s += F(a + i * h);
	}
	I = h * s;
	//cout << I << endl;
	return I;
}

double trapezoid_method(double a, double n, double h, double eps)
{
	double trapezoidal_integral = 0;
	for (int step = 0; step < n; step++) {
		const double x1 = a + step * h;
		const double x2 = a + (step + 1)*h;

		trapezoidal_integral += 0.5*(x2 - x1)*(F(x1) + F(x2));
	}
	return trapezoidal_integral;
}

double F(double x) 
{
	return 19.0 * cos(x / 19.0) - (19.0 / x);
}

double dF(double x) 
{
	return -sin(x / 19.0) + (19 / (x * x));
}

double P(double x)
{
	return 361 * sin(x / 19) - 19 * log(abs(x));
}
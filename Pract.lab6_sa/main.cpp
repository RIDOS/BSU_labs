#include <iostream>
#include <cmath>
#include <cstring>
#include <string>

using namespace std;

double centerRect(double a, double b, double n);
double Simpson(double a, double b, double n, double eps);
double P(double x);
double F(double x);
double dF(double x);

int main()
{
	system("chcp 1251>nul");
	double a, b, eps, N, T;
	int n;

	cout << "Ввести переменные a, b, n, e\n(Где a и b точки, n - кол-во разбиений, e - число эпсилон): ";
	cin >> a >> b >> n >> eps;
	// Формула Ньютона-Лейбница.
	/*
		Если фун-ция F непрерывна на отрезке [a,b] и 
		P(x) - любая ее первообразная на этом отрезке, то

		такая имеет равенство P(b) - P(a),
		где P(b) - первообразная от точки максимума,
		a P(a) - первообразная от точки минимума.
	*/
	N = P(b) - P(a);
	T = centerRect(a, b, n);

	while (abs(N - T) > eps)
	{
		T = centerRect(a, b, n*=2);
	}

	cout << "\nМетод Ньютона Лейбница: " << N << endl;
	cout << "Метод центральных прямоугольников: " << T << endl;
	cout << "Метод Симпсона: " << Simpson(a, b, n, eps) << endl;

	system("pause > nul");
}

// Формула центральных прямоугольников.
/*
	Определенный интеграл вычисляется следующим образом:
	F((a + b) / 2) * (b - a)
*/
double centerRect(double a, double b, double n)
{
	double h = (b - a) / n;
	double sum = (F(a) - F(b)) / 2;
	for (int i = 1; i < n; i++)
	{
		double x = a + h * i;
		sum += F(x);
	}

	return h * sum;
}


// Формула Симпсона.
/*
	Суть метода заключается в приближении подынтегральной функции 
	на отрезке [a, b] интерполяционным многочленом второй степени p2(x), 
	то есть приближение графика функции на отрезке параболой.

	Формула:
	(b - a) / 6 * (f(a) + 4*f(a + b / 2) + f(b))
*/
double Simpson(double a, double b, double n, double eps)
{
	double h = (b - a) / n;
	double sum1 = 0.0, sum2 = 0.0;
	for (int i = 1; i <= n; i++)
	{
		double x = a + i * h;
		if (i <= n - 1)
		{
			sum1 += F(x);
		}

		double xk = a + (i - 1) * h;
		sum2 += F((x + xk) / 2);
	}
	double result = h / 3.0 * (1.0 / 2.0 * F(a) + sum1 + 2 * sum2 + 1.0 / 2.0 * F(b));
	return result;
}

// Функция.
double F(double x)
{
	return 7.0 * cos(x / 7.0) - (7.0 / x);
}

// Производная от функиции F.
double dF(double x)
{
	return -sin(x / 7.0) + (7.0 / (x * x));
}

// Первообразная от функции F.
double P(double x)
{
	return 49 * sin(x / 7.0) - 7.0 * log(x);
}
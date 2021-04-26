#include "pch.h"
#include <iostream>
#include <cmath>
#include <cstring>
#include <string>

using namespace std;

void methodNewton(float a, float b, float mH);
float methodHord(float a, float b);
float F(float x);
float dF(float x);
float d2F(float x);


struct Coord
{
	float X;
	float Y;
};

bool poisk(Coord* arr, float a, float b, float h);

int main()
{
	system("chcp 1251>nul");
	bool  b1 = true, b_2 = false;
	string str, wp;
	int num, wibork;

	do {
		cout <<
			"Решение трансцендентных уравнений: (Введите номер в консоль)\n"
			<<
			"1. Отделение корней\n"
			<<
			"2. Уточнение приблеженного значения корня.\n"
			<<
			endl;

		cin >> num;

		system("cls");
		float a, M, b, h, mH;
		Coord* cor_ = new Coord[100];

		switch (num)
		{
		case 1:
			cout << "Отделение корней\nВведите промежуток [a, b] и M:" << endl;
			cout << "a -> ";
			cin >> a;
			cout << "b -> ";
			cin >> b;
			cout << "M -> ";
			cin >> M;

			h = (b - a) / M;

			poisk(cor_, a, b, h);

			if (b) {
				cout << "Уточнить приблеженное значение? (Да/нет)";
				cin >> wp;

				if (!(wp == "Да" || wp == "да")) {
					break;
				}
				else {
					b_2 = true;
					cout << "Введите число:\t";
					system("pause>nul");
					cin >> wibork;
					a = cor_[wibork].X;
					b = cor_[wibork].Y;
					system("cls");
				}
			}
		case 2:
			if (!b_2) {
				cout << "Уточнение приблеженного значения корня.\nВведите промежуток [a, b]:" << endl;
				cout << "a -> ";
				cin >> a;
				cout << "b -> ";
				cin >> b;
			}
			else {
				cout << "Уточнение приблеженного значения корня." << endl;
			}


			mH = methodHord(a, b);
			methodNewton(a, b, mH);
			b_2 = false;
			break;
		default:
			cout << "Вы ввели неверные данные..." << endl;
			system("pause > nul");
			break;
		}

		cout << "Перезапустить программу? ";
		cin >> str;

		system("cls");

		b1 = (str == "Да" || str == "да") ? true : false;
	} while (b1);


	system("echo create by RIDOS");
	system("pause");
	return 0;
}

void methodNewton(float a, float b, float mH) {
	float x0, xn;
	cout << "\nПо методу Ньютона:" << endl;
	if (F(a) * F(b) > 0) {
		cout << "Корней нет!" << endl;
	}
	else {
		x0 = mH;
		float eps = 0.001, f, df;
		int iter = 0;

		cout << "x0= " << a << " \n";
		do {
			f = F(a);
			df = dF(a);
			a = a - f / df;
			iter++;
			cout << "x0= " << a << "\n";
		} while (fabs(f) > 0.001 && iter < 20000);
		cout << iter << " iterations" << endl;

		cout << "\nОтвет: x = " << a;
		cout << endl << endl;
	}
}


float methodHord(float a, float b) {
	cout << "\nПо методу Хорд:" << endl;
	int iter = 0;
	while (fabs(F(b)) > 0.001)
	{
		a = b - ((b - a) * F(b)) / (F(b) - F(a));
		b = a - ((a - b) * F(a)) / (F(a) - F(b));
		cout << "iter " << ++iter << "\t" << b << endl;
	}
	return b;
}

float F(float x)
{
	return 19.0 * cos(x / 19.0) - (19.0 / x);
}

float dF(float x) {
	return -sin(x / 19.0) + (19 / (x*x));
}

float d2F(float x) {
	return -0.0562*cos(x / 19.0) - (38.0 / (pow(x, 3)));
}

bool poisk(Coord* arr, float a, float b, float h) {
	bool bi = false;
	int counter = 0;
	float k = a;
	do {
		if (F(k) * F(k + h) < 0) {
			arr[counter].X = k;
			arr[counter].Y = k + h;
			cout << counter + 1 << ".\t" << arr[counter].X << "\t" << arr[counter].Y << endl;
			counter++;
			bi = true;
		}
		k += h;
	} while (k <= b);
	counter = 0;
	return bi;
}
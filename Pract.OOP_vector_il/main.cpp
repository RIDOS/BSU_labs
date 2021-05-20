#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class dualVector
{
    // Публичные данные, для того, чтобы передать в дочерний класс.
public:
    float a;
    float b;

    dualVector()
    {
        // Конструктор по умолчанию.
        a = b = 0;
    }

    dualVector(float _a, float _b) : a(_a), b(_b)
    {
        // Конструктор с параметрами. Принемаем два значения.
    }

    // Метод сложения веторов.
    void plusVector(float c, float d)
    {
        cout << "(" << a + c << "; " << b + d << ")" << endl;
    }
    // Метод вычитания векторов.
    void minusVector(float c, float d)
    {
        cout << "(" << a - c << "; " << b - d << ")" << endl;
    }
    // Умножение вектора на число.
    void multipleVector(float k)
    {
        cout << "(" << a * k << "; " << b * k << ")" << endl;
    }
    // Деление вектора на число.
    void divVector(float k)
    {
        cout << "(" << a / k << "; " << b / k << ")" << endl;
    }
    // Скалярное число
    void skalyar(float c, float d)
    {
        float cosa;
        cout << "|a| = " << sqrt(a * a + b * b) << endl;
        cout << "|b| = " << sqrt(c * c + d * d) << endl;
        cout << "a * b = " << a * c + b * d << endl;
        cout << "cosa = " << (cosa = ((a * c + b * d) / ((sqrt(a * a + b * b)) * (sqrt(c * c + d * d))))) << endl;

        cout << "a * b = |a| * |b| * cosa = " << (sqrt(a * a + b * b) * sqrt(c * c + d * d) * cosa) << endl;
    }

    ~dualVector()
    {
        // Деструктор класса.
    }
};

class trialVector : dualVector
{
public:
    float c;
    trialVector(): dualVector(a, b)
    {
        a = b = c = 0;
    }

    trialVector(float a, float b, float _c): c(_c), dualVector(a, b)
    { }

    void plusVector(float d, float e, float f)
    {
        cout << "(" << a + d << "; " << b + e << "; " << c + f << ")" << endl;
    }

    void plusVectorAndK(trialVector tv, float alph, float eps)
    {
        cout << "(" << alph * a + eps * tv.a << "; " << alph * b + eps * tv.b << "; " << alph * c + eps * tv.c << ")" << endl;
    }
};

int main()
{
    system("chcp 1251>nul");
    int i = 0;
    cout << "\nВектора в двухмерном пространстве: \n" << endl;

    while (i < 15)
    {
        cout << "-";
        ++i;
    }
    cout << endl;

    dualVector dv(1, 2);
    dv.plusVector(1, 2);
    dv.minusVector(2, 4);
    dv.multipleVector(2);
    dv.divVector(5);
    dv.skalyar(6, 6);
    
    i = 0;
    while (i < 15)
    {
        cout << "-";
        ++i;
    }
    cout << endl;

    cout << "\n Вектора в трехмерном пространстве: \n" << endl;

    i = 0;
    while (i < 15)
    {
        cout << "-";
        ++i;
    }
    cout << endl;

    trialVector tv1(1, 2, 3);
    trialVector tv(1, 2, 3);
    tv.plusVector(3, 2, 1);
    tv.plusVectorAndK(tv1, 2, 2);

    i = 0;
    while (i < 15)
    {
        cout << "-";
        ++i;
    }
    cout << endl;
}
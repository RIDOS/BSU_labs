#include <iostream>
#include <time.h>
#include <cmath>
 
using namespace std;
 
 
struct length_of {
    double A;
    double B;
    double C;
};
 
void massIn(length_of triangle[], int n);
void massOu(length_of triangle[], int n);

int kolRav(length_of triangle[], int n);
double perTriangle(length_of triangle[], int n);

 
int main()
{
    setlocale(LC_ALL, "rus");
    cout << "H0w much triangles? -> ";

    int n;
    cin >> n;
    cout << "\nTriangles is -> " << n <<". \n\n";
    
    length_of* triangel = new length_of[n];

    cout << "Сформированные треугольники -> " << endl;
    massIn(triangel, n);
    massOu(triangel, n);
 
    cout << "\nCounting the number of isosceles triangles is -> " << kolRav(triangel, n) << "\n"
        << "The perimeter is  -> " << perTriangle(triangel, n) << "\n"
        << "End program...\n\n";

    delete [] triangel;
    cout << "\nMass out." <<endl;
    
    return 0;
 
}

void massIn(length_of triangle[], int n) {
    srand(time(0));

    for (int i = 0; i < n; i++)
    {
        triangle[i].A = 15/*rand() % 5 - 2*/;
        triangle[i].B = 15/*rand() % 7 - 3*/;
        triangle[i].C = 15/*rand() % 9 - 3*/;
    }
    
}

void massOu(length_of triangle[], int n) {
    for (int i = 0; i < n; i++)
    {
        cout << "\nA -> " << triangle[i].A << endl;
        cout << "B -> " << triangle[i].B << endl;
        cout << "C -> " << triangle[i].C << "\n\n";
    }
    
}

int kolRav(length_of triangle[], int n) {
    int kol = 0;
    for (int i = 0; i < n; i++)
        if (triangle[i].A == triangle[i].B) kol++;
    

    return kol;
}

double perTriangle(length_of triangle[], int n) {
    double S, p;
    for (int i = 0; i < n; i++)
    {
        p = (triangle[i].A + triangle[i].B + triangle[i].C)/2;
        S += sqrt(p*(p-triangle[i].A)*(p-triangle[i].B)*(p-triangle[i].C));
    }

    return S;
}

/********************************************************************************************************/


#include <iostream>
#include <time.h>
#include <cmath>
 
using namespace std;
 
 
struct length_of {
    double A;
    double B;
    double C;
};
 
void massIn(length_of triangle[], int n);
void massOu(length_of triangle[], int n);

int kolRav(length_of triangle[], int n);
double perTriangle(length_of triangle[], int n);

bool thisFT(int A, int B, int C);

 
int main()
{
    setlocale(LC_ALL, "rus");
    cout << "H0w much triangles? -> ";

    int n;
    cin >> n;
    cout << "\nTriangles is -> " << n <<". \n\n";
    
    length_of* triangel = new length_of[n];

    cout << "Сформированные треугольники -> " << endl;
    massIn(triangel, n);
    massOu(triangel, n);
 
    cout << "\nCounting the number of isosceles triangles is -> " << kolRav(triangel, n) << "\n"
        << "The perimeter is  -> " << perTriangle(triangel, n) << "\n"
        << "End program...\n\n";

    delete [] triangel;
    cout << "\nMass out." <<endl;
    
    return 0;
 
}

void massIn(length_of triangle[], int n) {
    srand(time(0));

    for (int i = 0; i < n; i++)
    {
        triangle[i].A = rand() % 5 + 2;
        triangle[i].B = rand() % 7 + 3;
        triangle[i].C = rand() % 9 + 3;
    }
    
}

void massOu(length_of triangle[], int n) {
    for (int i = 0; i < n; i++)
    {
        if (thisFT(triangle[i].A, triangle[i].B, triangle[i].C)) {
            cout << "\nA -> " << triangle[i].A << endl;
            cout << "B -> " << triangle[i].B << endl;
            cout << "C -> " << triangle[i].C << "\n\n";
        }
        else
            cout << "Не существует треугольника с такими параметрами." << endl;
    }
    
}

int kolRav(length_of triangle[], int n) {
    int kol = 0;
    for (int i = 0; i < n; i++)
        if (triangle[i].A == triangle[i].B) kol++;
    

    return kol;
}

double perTriangle(length_of triangle[], int n) {
    double S, p;
    for (int i = 0; i < n; i++)
    {
        p = (triangle[i].A + triangle[i].B + triangle[i].C)/2;
        S += sqrt(p*(p-triangle[i].A)*(p-triangle[i].B)*(p-triangle[i].C));
    }

    return S;
}

bool thisFT(int A, int B, int C) {
    if (A + B > C && A + C > B && B + C > A)
        return true;
    else
        return false;
}
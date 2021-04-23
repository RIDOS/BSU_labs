#include <iostream>
#include <math.h>

using namespace std;

class Complex {
/*params.    */
private:
    float a, bi;
/*construct. */
public:
    Complex(float A, float Bi) {
        /*Чтобы был. */
        a = A;
        bi = Bi;
        cout << "z = " << a << " + (" << bi << ")i" << endl << endl;
    }

    float complexSop(float di) {
        return di = -di;
    }

    void plusComplex(float c,float di) {
        cout << "z = " << (a + c) << " + (" << (bi + di) << ")i"<< endl<<endl;
    }

    void minusComplex(float c,float di) {
        cout << "z = " << (a - c) << " + (" << (bi - di) << ")i"<< endl<<endl;
    }

    void divComplex(float c,float di) {
        cout << "z = " << (a*c + bi*di) << " + (" << (bi * c - a * di) << ")i / " << (c*c + di*di) << endl<<endl;
    }

    void getComplex() {
        cout << "z = " << a << " + (" << bi << ")i" << endl << endl;
    }
};


int main() {
    setlocale(LC_ALL, "rus");

    Complex psd(6, 3);

    // psd.complexSop();
    psd.getComplex();
    psd.plusComplex(-26,54);
    psd.minusComplex(-26,54);
    psd.divComplex(2, 4);

    return 0;
}
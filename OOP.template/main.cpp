#include <iostream>
#include <assert.h>

using namespace std;

template<class T>
class MyClass {
private:
    T* arr;
    int arr_lenght;
public:
    MyClass() {
        arr_lenght = 0;
        arr = nullptr;
    }

    MyClass(int lenght) {
        arr_lenght = lenght;
        arr = new T[arr_lenght];
    }

    ~MyClass() {
        delete[] arr;
    }

    T& operator[](int index)
    {
        assert(index >= 0 && index < arr_lenght);
        return arr[index];
    }

    void eraseArr() {
        delete[] arr;
        arr_lenght = 0;
        arr = nullptr;
    }

    // Добавление элементов

    // Удаление элементов
    

    int getLenght();
};

template<typename T>
int MyClass<T>::getLenght() { return arr_lenght; }

int main()
{
    system("chcp 1251>nul");
    cout << "Create by RIDOS..." << endl;
    /*
        Для того чтобы вывести большее количество переменных,
        поменяй значение N. 
        
        (Буквы в таблице ASCII начинаются с 65 до 90)
    */
    int N = 26;

    MyClass<int> intArr(N);
    MyClass<double> doubleArr(N);
    MyClass<char> charArr(N);
    
    for (int i = 0; i < intArr.getLenght(); i++)
    {
        intArr[i] = i;
        doubleArr[i] = i + 0.5;
        charArr[i] = i + 65;
    }

    cout << "\nint" << "\t" << "double" << "\t" << "char" << endl;

    for (int i = 0; i < intArr.getLenght(); i++)
    {
        cout << intArr[i] << "\t" << doubleArr[i] << "\t" << charArr[i] << endl;
    }

    system("pause>nul");
}
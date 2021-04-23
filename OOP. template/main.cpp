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
    void push_back(T value) {
        T* A2;

        try
        {
            A2 = new T[++arr_lenght];

            for (int i = 0; i < arr_lenght - 1; i++)
            {
                A2[i] = arr[i];
            }

            A2[arr_lenght - 1] = value;

            if ((arr_lenght - 1) > 0)
                delete[] arr;

            arr = A2;
        }
        catch (bad_alloc e)
        {
            arr_lenght = 0;
            cout << "Ошибка: " << e.what() << endl;
        }
    }

    // Объединение двух массивов
    MyClass& operator = (const MyClass& _A) {
        if (arr_lenght > 0)
            delete[] arr;

        try
        {
            arr = new T[_A.arr_lenght];
            arr_lenght = _A.arr_lenght;

            for (int i = 0; i < arr_lenght; i++)
            {
                arr[i] = _A.arr[i];
            }
        }
        catch (bad_alloc e)
        {
            arr_lenght = 0;
            cout << "Ошибка: " << e.what() << endl;
        }
        return *this;
    }
    
    // Удаление последнего элемента
    void delLast() {
        arr_lenght--;
    }


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
    int N = 5;

    MyClass<int> intArr(N);
    MyClass<double> doubleArr(N);
    MyClass<char> charArr(N);

    MyClass<int> intArr_doub(N);

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

    cout << "\nУдаление последнего элемента..." << endl;
    intArr.delLast();
    for (int i = 0; i < intArr.getLenght(); i++)
    {
        cout << intArr[i] << " ";
    }
    cout << endl;

    cout << "\nДобавление нового элемента..." << endl;
    intArr.push_back(99);
    for (int i = 0; i < intArr.getLenght(); i++)
    {
        cout << intArr[i] << " ";
    }
    cout << endl;

    cout << "\nОбьединение массивов..." << endl;
    intArr_doub = intArr;
    for (int i = 0; i < intArr.getLenght(); i++)
    {
        cout << intArr_doub[i] << " ";
    }
    cout << endl;

    system("pause>nul");
}
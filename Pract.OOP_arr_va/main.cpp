#include <iostream>
#include <string>
 
using namespace std;
 
class Mass
{
public:
    Mass(): mass(nullptr), _count(0)
    {
        // Без аргументов.
    }
    Mass(int count): mass(new string[count]), _count(count)
    {
        cout << "Введите 1 для автоматического ввода, либо 2 для ручного: ";
        int chous;
        cin >> chous;
 
        if (chous == 1)
        {
            for (int i = 0; i < count; i++)
            {
                mass[i] = to_string(rand() % 9) + " + " + to_string(rand() % 9) + "i";
            }
        }
        else if (chous == 2)
        {
            for (int i = 0; i < count; i++)
            {
                cin >> mass[i];
            }
        }
        else
            cout << "Введино неверное число." << endl;
    }
    void printArr()
    {
        cout << "Компексные чила: " << endl;
        for (int i = 0; i < _count; i++)
        {
            cout << i + 1 << ") " << mass[i] << endl;
        }
    }
    ~Mass()
    {
        delete[] mass;
    }
private:
    string* mass;
    int _count;
};
 
int main()
{
    system("chcp 1251>nul");
 
    Mass arr(12);
    arr.printArr(); 
}
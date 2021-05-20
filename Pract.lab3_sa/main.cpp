#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;
int main()
{
    setlocale(LC_ALL, "ru");
    char arr[255];
    int lenght = 0, j = 0, member = 0, max = 0;
    string str;

    // Динамический массив строк (вектор), от кол-ва чисел в строке.
    vector<string> str_arr;

    cin.getline(arr, 255);

    // Подсчет кол-во чисел в строке.
    for (int i = 0; i < size(arr); i++)
    {
        /*
            Проходим пока i не будет равна кол-ву элементов в массиве arr.
        */
        // Если символ не евляется пробелом и последующий член не рав концу строки j++.
        if (arr[i] == ' ' || arr[i+1] == '\0')
            j++;
        // Если конец строки, то запиши значение j в lenght.
        if (arr[i] == '\0')
            lenght = j;
    }

    // Обнуляем значение.
    j = 0;

    // Запись строки в массив строк.
    for (int i = 0; i < size(arr) + 1; i++)
    {
        if (arr[i] != ' ' && arr[i] != '\0')
            str += arr[i];
        else
        {
            str_arr.push_back(str);
            str.clear();
        }
            
    }

    // Отчищаем строку для дальнейшего использования.
    str.clear();

    // Проходимся по всем числам.
    for (int i = 0; i < str_arr.size(); i++)
    {
        // Переменная для прохода по всей строке.
        int iter = 0;
        // Переменная для извлечения индекса из строки.
        string l = str_arr[i];
        // Записывавем символ в переменную member.
        while (iter < l.length())
        {
            /*
                Проходим до тех пор пока iter не станет равен числу элементов в строке.
            */
            member += l[iter];
            iter++;
        }
        // Находим максимум.
        if (member > max)
        {
            // Присваеваем строку member максимуму.
            max = member;
            // Строку записываем в str.
            str = str_arr[i];
            // обнуляем значение, для повторного использования.
            member = 0;
        }
    }

    

    cout << "Исходная строка    : " << arr << "\n";
    cout << "Самое длинное число: " << str << "\n";
    
    system("pause>nul");
}
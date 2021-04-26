#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <Windows.h>
using namespace std;

const int N = 255;

void file_out(); // Вывод из файла.
void file_init(); // Создать файл, если последний отсутсвует.

void sort_of_title();
void sort_of_country();

void out_sort_of_count();

void dock_country_and_count();

void sort_scroll_of_title();
void sort_scroll_of_country();

struct Tovar
{
    string title;
    string country;
    int count;
};

int structure_init(Tovar* tovar);

int main()
{
    system("chcp 1251 > nul");
    fstream file("text.txt", fstream::out | fstream::app);
    bool restart = true;
    int result;

    if (!file.is_open()) std::cout << "Ошибка! Файл не найден..." << endl;
    else 
    {
        do
        {
            cout << "1. Вывод всех товаров." << endl;
            cout << "2. Сортировка исходного массива структур\nпо наименованию товара в алфавитном порядкe." << endl;
            cout << "3. Сортировка исходного массива структур по стране в алфавитном порядке." << endl;
            cout << "4. Сортировка выходного массива структур в порядке убывания объема поставки." << endl;
            cout << "5. Сформировать перечень объемов партий в штуках с указанием количества наименований товаров этого объема." << endl;
            cout << "6. Сортировка перечня по количеству наименований товара в порядке убывания." << endl;
            cout << "7. Сортировка перечня по объему партий в порядке возрастания." << endl;
            cout << "8. Выход из программы." << endl;
            cout << "\nВаш выбор (1-8): ";
            cin >> result;
            cout << endl;

            switch (result)
            {
            case 1:
                //file_init();
                file_out();
                break;
            case 2:
                sort_of_title();
                break;
            case 3:
                sort_of_country();
                break;
            case 4:
                out_sort_of_count();
                break;
            case 5:
                dock_country_and_count();
                break;
            case 6:
                sort_scroll_of_title();
                break;
            case 7:
                sort_scroll_of_country();
                break;
            case 8:
                restart = false;
                return 0;
            default:
                break;
            }

            cout << "\nДля продолжения, нажмите Enter..." << endl;
            system("pause>nul");
            system("cls");
        }     
        while (restart);
    }
    file.close();
}

void file_init()
{
    ofstream file;
    file.open("text.txt");
    file << " _______________________________________________________" << endl;
    file << "| "<< setw(10) << "Наименование товара |" << setw(10) << " Страна" << setw(20) << "| Кол-во " << setw(4) << "|" << endl;
    file << "|_____________________|_____________________|___________|" << endl;
    file << "| " << "Cосиска " << setw(23) << " | Казахстан" << setw(13) << " | " << "105 " << setw(7) << "|" << endl;
    file << "| " << "Карандаш " << setw(19) << " | Ереван" << setw(16) << " | " << "96 " << setw(8) << "|" << endl;
    file << "| " << "Колбаса " << setw(20) << " | Египет" << setw(16) << " | " << "5 " << setw(9) << "|" << endl;
    file << "| " << "Ручка " << setw(24) << " | Германия" << setw(14) << " | " << "8 " << setw(9) << "|" << endl;
    file << "| " << "Фрикаделька " << setw(19) << " | Швейцария" << setw(13) << " | " << "1641 " << setw(6) << "|" << endl;
    file << "|_______________________________________________________|" << endl;
    file.close();
}

int structure_init(Tovar* tovar)
{
    fstream file;
    int _char = 0;
    string text, source;
    int count = 0, iteration = 0;

    file.open("text.txt", fstream::in | fstream::out | fstream::app);

    while ((_char = file.get()) != EOF)
    {
        if (char(_char) != '\n')
            if (char(_char) != '\t')
            {
                text += char(_char);
                source += char(_char);
                if (count == 0)
                    tovar[iteration].title = source;
                else if (count == 1)
                    tovar[iteration].country = source;
                else
                    tovar[iteration].count = atoi(source.c_str());
            }
            else
            {
                text += " ";
                if (count++ != 2)
                    source.clear();
            }
        else
        {
            iteration++;
            text += '\n';
            count = 0;
            source.clear();
        }
    }
    file.close();
    return iteration;
}

void file_out()
{
    Tovar* tovar = new Tovar[N];
    int iteration = structure_init(tovar);

    cout << "Наименование товара" << setw(10) << "Страна" << setw(20) << "Кол-во" << setw(4) << endl;
    for (int i = 0; i < iteration + 1; i++)
    {
        cout << tovar[i].title << setw(30 - tovar[i].title.size()) << tovar[i].country << setw(17) << tovar[i].count << endl;
    }
}

void sort_of_title()
{
    cout << "Сортировка исходного массива структур по наименованию товара в алфавитном порядке:" << endl;
    Tovar* tovar = new Tovar[N];
    int iteration = structure_init(tovar);
    int buffer_iteration = iteration + 1;

    int  fl;
    Tovar temp;
    do
    {
        fl = 0;
        iteration--;

        for (int i = 0; i < iteration; i++)
        {
            if (tovar[i].title > tovar[i + 1].title)
            {
                fl = 1;
                temp = tovar[i];
                tovar[i] = tovar[i + 1];
                tovar[i + 1] = temp;
            }
        }
    }     
    while (fl == 1);


    cout << "Наименование товара" << setw(10) << "Страна" << setw(20) << "Кол-во" << setw(4) << endl;
    for (int i = 0; i < buffer_iteration; i++)
    {
        cout << tovar[i].title << setw(30 - tovar[i].title.size()) << tovar[i].country << setw(17) << tovar[i].count << endl;
    }
}

void sort_of_country()
{
    cout << "Сортировка исходного массива структур по стране в алфавитном порядке:" << endl;
    Tovar* tovar = new Tovar[N];
    int iteration = structure_init(tovar);
    int buffer_iteration = iteration + 1;

    int fl;
    Tovar temp;
    do
    {
        fl = 0;
        iteration--;

        for (int i = 0; i < iteration; i++)
        {
            if (tovar[i].country > tovar[i + 1].country)
            {
                fl = 1;
                temp = tovar[i];
                tovar[i] = tovar[i + 1];
                tovar[i + 1] = temp;
            }
        }
    }     while (fl == 1);


    cout << "Наименование товара" << setw(10) << "Страна" << setw(20) << "Кол-во" << setw(4) << endl;
    for (int i = 0; i < buffer_iteration; i++)
    {
        cout << tovar[i].title << setw(30 - tovar[i].title.size()) << tovar[i].country << setw(17) << tovar[i].count << endl;
    }
}

void out_sort_of_count()
{
    cout << "Сортировка выходного массива структур в порядке убывания объема поставки:" << endl;
    ofstream out_file;
    out_file.open("output.txt");
    
    if (out_file.is_open())
    {
        Tovar* tovar = new Tovar[N];
        int iteration = structure_init(tovar);
        int buffer_iteration = iteration + 1;

        int fl;
        Tovar temp;
        do
        {
            fl = 0;
            iteration--;

            for (int i = 0; i < iteration; i++)
            {
                if (tovar[i].count > tovar[i + 1].count)
                {
                    fl = 1;
                    temp = tovar[i];
                    tovar[i] = tovar[i + 1];
                    tovar[i + 1] = temp;
                }
            }
        } while (fl == 1);


        cout << "Наименование товара" << setw(10) << "Страна" << setw(20) << "Кол-во" << setw(4) << endl;
        for (int i = 0; i < buffer_iteration; i++)
        {
            out_file << tovar[i].title << setw(30 - tovar[i].title.size()) << tovar[i].country << setw(17) << tovar[i].count << endl;
            cout << tovar[i].title << setw(30 - tovar[i].title.size()) << tovar[i].country << setw(17) << tovar[i].count << endl;
        }
        cout << "\n\nВыходной документ был сформирован." << endl;
    }
    else
        cout << "Ошибка открытия файла..." << endl;

    out_file.close();
}

void dock_country_and_count()
{
    cout << "Сформировать перечень объемов партий в штуках с указанием количества наименований товаров этого объема:" << endl;
    ofstream out_file;
    out_file.open("scrol.txt");

    if (out_file.is_open())
    {
        string buf_one;
        Tovar* tovar = new Tovar[N];
        int iteration = structure_init(tovar);
        int buffer_iteration = iteration + 1;


        cout << " _______________________________________________________" << endl;
        cout << "| Объем партий (шт.)" << setw(20) << "| Наименование товаров" << setw(15) << "|" << endl;
        cout << "|___________________|___________________________________|" << endl;
        out_file << " _______________________________________________________" << endl;
        out_file << "| Объем партий (шт.)" << setw(20) << "| Наименование товаров" << setw(15) << "|" << endl;
        out_file << "|___________________|___________________________________|" << endl;
        for (int i = 0; i < buffer_iteration; i++)
        {
            buf_one = to_string(tovar[i].count);
            out_file << "| " << tovar[i].count << setw(20 - buf_one.size()) << "| " << tovar[i].title << setw(35 - tovar[i].title.size()) << "|" << endl;
            cout << "| " << tovar[i].count << setw(20 - buf_one.size()) << "| " << tovar[i].title << setw(35 - tovar[i].title.size()) << "|" << endl;
        }
        cout << "|___________________|___________________________________|" << endl;
        out_file << "|___________________|___________________________________|" << endl;
        cout << "\n\nВыходной документ был сформирован." << endl;
    }
    else
        cout << "Ошибка открытия файла..." << endl;

    out_file.close();
}

void sort_scroll_of_title()
{
    cout << "Сортировка перечня по объему партий в порядке возрастания:" << endl;
    Tovar* tovar = new Tovar[N];
    int iteration = structure_init(tovar);
    int buffer_iteration = iteration + 1;
    string buf_one;

    int fl;
    Tovar temp;
    do
    {
        fl = 0;
        iteration--;

        for (int i = 0; i < iteration; i++)
        {
            if (tovar[i].title > tovar[i + 1].title)
            {
                fl = 1;
                temp = tovar[i];
                tovar[i] = tovar[i + 1];
                tovar[i + 1] = temp;
            }
        }
    } while (fl == 1);


    cout << " _______________________________________________________" << endl;
    cout << "| Объем партий (шт.)" << setw(20) << "| Наименование товаров" << setw(15) << "|" << endl;
    cout << "|___________________|___________________________________|" << endl;

    for (int i = 0; i < buffer_iteration; i++)
    {
        buf_one = to_string(tovar[i].count);
        cout << "| " << tovar[i].count << setw(20 - buf_one.size()) << "| " << tovar[i].title << setw(35 - tovar[i].title.size()) << "|" << endl;
    }
    cout << "|___________________|___________________________________|" << endl;
}

void sort_scroll_of_country()
{
    cout << "Сортировка перечня по объему партий в порядке возрастания:" << endl;
    Tovar* tovar = new Tovar[N];
    int iteration = structure_init(tovar);
    int buffer_iteration = iteration + 1;
    string buf_one;

    int fl;
    Tovar temp;
    do
    {
        fl = 0;
        iteration--;

        for (int i = 0; i < iteration; i++)
        {
            if (tovar[i].count > tovar[i + 1].count)
            {
                fl = 1;
                temp = tovar[i];
                tovar[i] = tovar[i + 1];
                tovar[i + 1] = temp;
            }
        }
    } while (fl == 1);


    cout << " _______________________________________________________" << endl;
    cout << "| Объем партий (шт.)" << setw(20) << "| Наименование товаров" << setw(15) << "|" << endl;
    cout << "|___________________|___________________________________|" << endl; 
    
    for (int i = 0; i < buffer_iteration; i++)
    {
        buf_one = to_string(tovar[i].count);
        cout << "| " << tovar[i].count << setw(20 - buf_one.size()) << "| " << tovar[i].title << setw(35 - tovar[i].title.size()) << "|" << endl;
    }
    cout << "|___________________|___________________________________|" << endl;
}

#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

struct Chars
{
	int number;
	char symbol;
};

void createFile(int count, Chars* array);
void outOfFile(string nameFile);
void outNewFile(int count, Chars* array);

int main()
{
	int count;
	system("chcp 1251>nul");
	cout << "Студ. Имаев 16ПИ." << endl;
	cout << "Какое кол-во символов будет записано в файл: ";
	cin >> count; cout << endl;

	Chars* array = new Chars[count];
	createFile(count, array);
	cout << "Текст в файле:" << endl;
	outOfFile("text.txt");

	cout << "Новый файл:" << endl;
	outNewFile(count, array);
	outOfFile("outFile.txt");
}

void createFile(int count, Chars* array)
{
	int temp;
	ofstream file;
	file.open("text.txt");

	for (int i = 0; i < count; i++)
	{
		file << (temp = (rand() % 10)) << setw(10 - sizeof(temp)) << "*" << setw(10) << char(65 + rand() % 10) << endl;
	}

	file.close();
}

void outOfFile(string nameFile)
{
	int _char = 0;
	string text;

	fstream file;
	file.open(nameFile, fstream::in | fstream::out | fstream::app);

	while ((_char = file.get()) != EOF)
	{
		if (char(_char) != '\n')
		{
			text += char(_char);
		}
		else
			text += "\n";
	}

	cout << text << endl;
}

void outNewFile(int count, Chars* array)
{
	fstream file;
	ofstream file_new;
	int number = 0, _char = 0, iter = 0;
	file.open("text.txt", fstream::in | fstream::app);
	file_new.open("outFile.txt");

	while ((_char = file.get()) != EOF)
	{
		if (char(_char) != '\n')
		{
			if (char(_char) != '\t' && char(_char) != ' ' && char(_char) != '*')
			{
				if (number++ == 0)
					array[iter].number = (_char - 48);
				else
					array[iter].symbol = char(_char);
			}
		}
		else
		{
			number = 0;
			iter++;
		}
	}

	for (int iteration = 0; iteration < count; iteration++)
	{
		for (int j = 0; j < array[iteration].number; j++)
		{
			file_new << array[iteration].symbol;
		}
		file_new << endl;
	}
	file.close();
	file_new.close();
}
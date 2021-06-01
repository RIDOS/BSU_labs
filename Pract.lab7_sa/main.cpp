#include <iostream>
#include <string>
#include <fstream>
using namespace std;
string inFile();
string newFile();
void zapic(string word, string fileName, int count);
void printFile(string nameFile);
int main()
{
    system("chcp 1251>nul");
    printFile(inFile());
    printFile(newFile());
}
string inFile()
{
	cout << "Cформированный файл:" << endl;
    string fileName = "arr.txt";
	ofstream file;
	file.open(fileName);
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			file << int(rand() % 15 - 1) << '.' << int(rand() % 10 + 1) << "f\t";
		}
		file << endl;
	}
	file.close();
    return fileName;
}
string newFile()
{
	cout << "Новый файл:" << endl;
    string fileName = "arr_new.txt";
	ifstream file_one("arr.txt");
	string text, word;
	int _char = 0, count = 0;
	float max = 0;
 
	while ((_char = file_one.get()) != EOF)
	{
		count++;
		if (char(_char) != '\n')
		{
			if (char(_char) != '\t')
			{
				text += char(_char);
			}
			else
			{
				if (max < stof(text))
				{
					max = stof(text);
					word = text;
				}
				text.clear();
			}
		}
	}
	cout << "Максимальное число: " << word << endl;
 
	zapic(word, fileName, count);
 
	file_one.close();
    return fileName;
}
void zapic(string word, string fileName, int count)
{
	ifstream file_one("arr.txt");
	ofstream new_file;
	new_file.open(fileName);
	int _char = 0, iter = 0;
	float sum = 0;
	string text;
	bool b = false;
 
	while ((_char = file_one.get()) != EOF)
	{
		if (char(_char) != '\n')
		{
			if (char(_char) != '\t')
			{
				text += char(_char);
			}
			else
			{
				iter++;
				// Должно выполниться условие:
				/*
					1. Число совпадает,
					2. Число находится в первой половине файла.
				*/
				if ((text == word) && (count/2 < iter))
				{
					b = true;
				}
				if (b)
				{
					// Сумма всех последующих элементов.
					sum += stof(text);
				}
				text.clear();
			}
		}
	}
	new_file << sum;
}
void printFile(string nameFile)
{
	int _char = 0;
	string text;
 
	ifstream file(nameFile);
 
	while ((_char = file.get()) != EOF)
	{
		if (char(_char) != '\n')
		{
			text += char(_char);
		}
		else
			text += "\n";
	}
	file.close();
	cout << text << endl;
}
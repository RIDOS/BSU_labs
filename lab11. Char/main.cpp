#include <iostream>
 
using namespace std;
 
int k = 0;
 
int main()
{
	system("chcp 1251>nul");
 
	char ch[250], sl[30], sim[3] = { '.', '!', '?' };
	int lenght, count = 0, num = 0;
	int* mass;
 
	cout << "Введите текст:\t";
	cin.getline(ch, 250);
 
	cout << "Введите слово:\t";
	cin.get(sl, 80);
 
	lenght = sizeof(ch);
 
	for (int i = 0; i < lenght; i++)
	{
		int j = 0;
		while (j < sizeof(sim)) {
			if (ch[i] == sim[j])
				count++;
			j++;
		}
	}
 
	mass = new int[count];
 
	for (int i = 0; i < lenght; i++)
	{
		int j = 0;
		while (j < sizeof(sim)) {
			if (ch[i] == sim[j])
			{
				mass[k++] = i;
				/* Точка контроля 1
				cout << "Vot i = " << i << endl;
				cout << "Vot k = " << k << endl;
				cout << "Vot mass[i] = " << mass[k++] << endl;
				*/
			}
			j++;
		}
	}
	/* Точка контроля 2
	cout << "Вот сколько предложений - " << count << endl;
	cout << "mass[i] - " << mass[0] << endl;
	cout << "mass[i] - " << mass[1] << endl;
	cout << "mass[i] - " << mass[2] << endl;
	*/
 
	int j, max = 0;
	for (int i = 0; i < count; i++)
	{
		bool b = false;
		for (j = max; j < mass[i]; j++)
		{
 
			int p = 0;
			while (sizeof(ch) > p) {
				if (ch[j] == sl[p])
				{
					b = true;
				}
				p++;
			}
 
			max = j;
			//num++;
		}
		if (b) num++;
	}
 
	cout << "\nСлово \"" << sl << "\" в тексте встречается в " << num << " предложениях." << endl;
	cout << "Всего в тексте " << count << " предложений." << endl;
	system("pause");
	return 0;
}
 
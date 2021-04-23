#include <iostream>
#include <cstring>
#include <string>
 
using namespace std;
 
int getScobka(string str);
 
int main()
{
	system("chcp 1251>nul");
	string text = "()()((())))";
 
	cout << "" << getScobka(text) << endl;
 
	system("pause");
	return 0;
}
 
int getScobka(string str) {
	int left = 0, right = 0, tmp;
 
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '(')
			left++;
		if (str[i] == ')') {
			right++;
		}
 
		if (left < right) tmp = i;
	}
 
	if (left == right) return 0;
	else if (left > right) return -1;
	else return tmp;
}
#include<iostream>
#include<cmath>

using namespace std;

void arrSet(int* arr, int n, bool b);
void arrGet(int* arr, int n);
void arrMin(int* arr, int n);

int main()
{
    /* Переменная для ввода данных
     *
     * true - ручной ввод;
     * false - автоматический ввод;
    */
    bool b = false;
    int n, m;
    cout << "Input n -> ";
    cin >> n;

    /*cout << "Input m -> ";
    cin >> m;*/

    int* arr = new int[n];
    arrSet(arr, n, b);
    if(!b) arrGet(arr, n);
    arrMin(arr, n);

    cout << "\nEnd of program. Project by RIDOS.." << endl;
    return 0;
}

void arrSet(int* arr, int n, bool b) {
    for(int i = 0; i < n; i++) {
        if (b) {
            /* Для заполнения в ручную. */
            cout << "arr[" << i << "] = ";
            cin >> arr[i];
        }
        else {
            /* Для заполнения рандомными элементами. */
            arr[i] = rand() % 5 - 10;
        }  
    }
}

void arrGet(int* arr, int n) {
    cout << endl;
    for(int i = 0; i < n; i++)
        cout << "Mass[" << i << "] = " << arr[i] << endl;
}

void arrMin(int* arr, int n) {
    int min = arr[0] + arr[1], index = 0;
    for(int i = 0; i < n - 1; i++) {
        int tmp = arr[i] + arr[i+1];
        if (tmp < min) {
            min = tmp;
            index = i;
        }
    }
    cout << "\nНаименьший номер среди сумм = " << index << endl;
}
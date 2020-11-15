#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void Create(int* a, const int size, const int Low, const int High);
void Print(int* a, const int size);
int Max(int* a, const int size);
int Min(int* a, const int size);

void Create_r(int a[], const int size, const int Low, const int High, int i);
void Print_r(int* a, const int size, int i);
int Max_r(int* a, const int size, int i, int max);
int Min_r(int* a, const int size, int i, int min);

//ітераційний спосіб
void Create(int* a, const int size, const int Low, const int High)
{
    for (int i = 0; i < size; i++)
        a[i] = Low + rand() % (High - Low + 1);
}
void Print(int* a, const int size)
{
    for (int i = 0; i < size; i++)
        cout << "a[" << setw(2) << i << " ] = " << setw(4) << a[i] << endl;
    cout << endl;
}
int Max(int* a, const int size)
{
    int max = a[0];
    int maxIndex = 0;
    for (int i = 1; i < size; i++)
        if (a[i] > max) {
            max = a[i];
            maxIndex = i;
        }
    return maxIndex;
}
int Min(int* a, const int size)
{
    int min = a[0];
    int minIndex = 0;
    for (int i = 1; i < size; i++)
        if (a[i] < min) {
            min = a[i];
            minIndex = i;
        }
    return minIndex;
}



//рекурсивний спосіб
void Create_r(int* a, const int size, const int Low, const int High, int i)
{
    a[i] = Low + rand() % (High - Low + 1);
    if (i < size - 1)
        Create_r(a, size, Low, High, i + 1);
}
void Print_r(int* a, const int size, int i)
{
    cout << "a[" << setw(2) << i << " ] = " << setw(4) << a[i] << endl;
    if (i < size - 1)
        Print_r(a, size, i + 1);
    else
        cout << endl;
}
int Max_r(int* a, const int size, int i, int max)
{
    if (a[i] > a[max])
        max = i;
    if (i < size - 1)
        return Max_r(a, size, i + 1, max);
    else
        return max;
}
int Min_r(int* a, const int size, int i, int min)
{
    if (a[i] < a[min])
        min = i;
    if (i < size - 1)
        return Min_r(a, size, i + 1, min);
    else
        return min;
}


int main()
{
    srand((unsigned)time(NULL));
    system("chcp 1251");
    int size;
    const int n = 5;
    int Low = -10;
    int High = 10;
    cout << "Розмір масиву a["; cin >> size; cout << "]\n";
    int* a = new int[size];
    cout << "\nІтераційний спосіб" << endl;
    Create(a, n, Low, High);
    Print(a, n);
    int maxIndex = Max(a, n);
    int minIndex = Min(a, n);
    int c = a[maxIndex];
    a[maxIndex] = a[minIndex];
    a[minIndex] = c;
    cout << "Модифікований масив\n";
    Print(a, n);
    cout << "\nРекурсивний спосіб" << endl;
    Create_r(a, n, Low, High, 0);
    Print_r(a, n, 0);
    maxIndex = Max_r(a, n, 1, 0);
    minIndex = Min_r(a, n, 1, 0);
    c = a[maxIndex];
    a[maxIndex] = a[minIndex];
    a[minIndex] = c;
    cout << "Модифікований масив\n";
    Print_r(a, n, 0);
    return 0;
}

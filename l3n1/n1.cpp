#include <iostream.h>
#include <conio.h>

void main(void)
{
    int mas[] = { 2, 5, -8, 1, -4, 6, 3, -5, -9, 13, 0, 4, 9 };
    int n = sizeof(mas) / sizeof(int);
    int i, imin, imax;

    clrscr();

    // Вывод исходного массива
    for (i = 0; i < n; i++)
        cout << mas[i] << ' ';
    cout << endl;

    // Сортировка методом "мини-макса"
    for (i = 0; i < n - 1; i++)
    {
        imin = i;
        for (int j = i + 1; j < n; j++)
        {
            if (mas[j] < mas[imin])
                imin = j;
        }
        int temp = mas[i];
        mas[i] = mas[imin];
        mas[imin] = temp;
    }

    // Вывод отсортированного массива
    for (i = 0; i < n; i++)
        cout << mas[i] << ' ';
    cout << endl;
}
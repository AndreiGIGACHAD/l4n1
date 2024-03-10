#include <iostream>
using namespace std;

template <typename T>
void Sort(T* arr, size_t size) {
    for (size_t i = 0; i < size - 1; ++i) {
        for (size_t j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                T temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int mas[] = { 10, 20, 30, 11, 25, 32, 0 };
    size_t size = sizeof(mas) / sizeof(mas[0]);

    Sort(mas, size);

    for (size_t i = 0; i < size; ++i) {
        cout << "mas[" << i << "] = " << mas[i] << endl;
    }

    return 0;
}
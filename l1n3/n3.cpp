#include <iostream>

using namespace std;

void obmen(int, int);
void obmen2(int*, int*);
void obmen3(int&, int&);

int main() {
    int a = 2, b = 5;
    cout << "до обмена:\n";
    cout << "a= " << a << ", b= " << b << endl;

    obmen(a, b);
    cout << "после обмена 1: a= " << a << ", b= " << b << endl;

    obmen2(&a, &b);
    cout << "после обмена 2: a= " << a << ", b= " << b << endl;

    obmen3(a, b);
    cout << "после обмена 3: a= " << a << ", b= " << b << endl;

    return 0;
}

void obmen(int x, int y) {
    int temp = x;
    x = y;
    y = temp;
}

void obmen2(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void obmen3(int& x, int& y) {
    int temp = x;
    x = y;
    y = temp;
}
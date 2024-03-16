#include <iostream>

using namespace std;

int power(int base, int exponent);

int main() {
    int i, k;
    for (i = 0; i < 10; i++) {
        k = power(2, i);
        cout << "i = " << i << ", k = " << k << endl;
    }
    return 0;
}

int power(int base, int exponent) {
    int result = 1;
    for (int i = 0; i < exponent; i++) {
        result *= base;
    }
    return result;
}
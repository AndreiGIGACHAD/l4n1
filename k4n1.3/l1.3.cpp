#include <iostream>
#include <cstring>

using namespace std;

int main() {
    char src[] = "Hello, World!";
    char dest[20];
    strcpy_s(dest, src);
    cout << "������������� ������: " << dest << endl;
    return 0;
}
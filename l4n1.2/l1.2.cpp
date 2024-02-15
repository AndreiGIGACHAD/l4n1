#include <iostream>
#include <cstring>

using namespace std;

int main() {
    char str1[20] = "Hello";
    char str2[] = ", World!";
    strcat_s(str1, str2);
    cout << "—цепленные строки: " << str1 << endl;
    return 0;
}
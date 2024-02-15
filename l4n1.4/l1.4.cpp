#include <iostream>
#include <cstring>

using namespace std;

int main() {
    char str1[] = "Hello";
    char str2[] = "World";
    if (strcmp(str1, str2) == 0) {
        cout << " str1 è str2 ne ravni." << endl;
    }
    else {
        cout << " str1 è str2 ravni." << endl;
    }
    return 0;
}
#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

int length1(const char* str) {
    int length = 0;
    while (*str != '\0') {
        length++;
        str++;
    }
    return length;
}

int length2(const char* str) {
    int length = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        length++;
    }
    return length;
}

int length3(const char* str) {
    const char* ptr = str;
    while (*ptr) {
        ptr++;
    }
    return ptr - str;
}

char* copyString(const char* src) {
    int length = length1(src) + 1;
    char* dest = new char[length];
    strcpy_s(dest, length, src);
    return dest;
}

int compareStrings(const char* str1, const char* str2) {
    while (*str1 && *str2 && *str1 == *str2) {
        str1++;
        str2++;
    }
    return (*str1 - *str2);
}

char* concatenateStrings(const char* str1, const char* str2) {
    int length1 = strlen(str1);
    int length2 = strlen(str2);
    char* result = new char[length1 + length2 + 1];
    strcpy_s(result, length1 + length2 + 1, str1);
    strcat_s(result, length1 + length2 + 1, str2);
    return result;
}

int main() {
    char* str1 = new char[100];
    char* str2 = new char[100];

    strcpy_s(str1, 100, "qwerty");
    strcpy_s(str2, 100, "1234567890");

    cout << "Length of str1 (method 1): " << length1(str1) << endl;
    cout << "Length of str2 (method 2): " << length2(str2) << endl;
    cout << "Length of str1 (method 3): " << length3(str1) << endl;

    char* copiedStr = copyString(str1);
    cout << "Copied string: " << copiedStr << endl;

    int comparisonResult = compareStrings(str1, str2);
    if (comparisonResult == 0) {
        cout << "Strings str1 and str2 are equal." << endl;
    }
    else {
        cout << "Strings str1 and str2 are not equal." << endl;
    }

    char* concatenatedStr = concatenateStrings(str1, str2);
    cout << "Concatenation result: " << concatenatedStr << endl;

    delete[] str1;
    delete[] str2;
    delete[] copiedStr;
    delete[] concatenatedStr;

    return 0;
}
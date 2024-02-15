#include <iostream>
#include <cstring>

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

void copyString(const char* src, char* dest) {
    while (*src != '\0') {
        *dest = *src;
        src++;
        dest++;
    }
    *dest = '\0';
}

int compareStrings(const char* str1, const char* str2) {
    while (*str1 && *str2 && *str1 == *str2) {
        str1++;
        str2++;
    }
    return (*str1 - *str2);
}

void concatenateStrings(const char* str1, const char* str2, char* result) {
    while (*str1) {
        *result = *str1;
        str1++;
        result++;
    }
    while (*str2) {
        *result = *str2;
        str2++;
        result++;
    }
    *result = '\0';
}

int main() {
    char str1[] = "qwerty";
    char str2[] = "1234567890";
    char result[100]; 

    
    cout << "Length of str1 (method 1): " << length1(str1) << endl;
    cout << "Length of str2 (method 2): " << length2(str2) << endl;
    cout << "Length of str1 (method 3): " << length3(str1) << endl;

    
    char copiedStr[100];
    copyString(str1, copiedStr);
    cout << "Copied string: " << copiedStr << endl;

    
    int comparisonResult = compareStrings(str1, str2);
    if (comparisonResult == 0) {
        cout << "Strings str1 and str2 are equal." << endl;
    }
    else {
        cout << "Strings str1 and str2 are not equal." << endl;
    }

    
    concatenateStrings(str1, str2, result);
    cout << "Concatenation result: " << result << endl;

    return 0;
}
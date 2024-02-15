#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

int length(const char* str) {
    int length = 0;
    while (*str != '\0') {
        length++;
        str++;
    }
    return length;
}

char* copyString(const char* src) {
    int length = ::length(src) + 1;
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
    const char* strings[] = { "Hello", "World", "Welcome", "to", "the", "Programming", "World" };

    for (int i = 0; i < sizeof(strings) / sizeof(strings[0]); ++i) {
        cout << "String " << i + 1 << ": " << strings[i] << endl;
        cout << "Length: " << length(strings[i]) << endl;

        char* copiedStr = copyString(strings[i]);
        cout << "Copied string: " << copiedStr << endl;

        int comparisonResult = compareStrings(strings[i], "World");
        if (comparisonResult == 0) {
            cout << "String is equal to 'World'." << endl;
        }
        else {
            cout << "String is not equal to 'World'." << endl;
        }

        char* concatenatedStr = concatenateStrings(strings[i], "!");
        cout << "Concatenated string: " << concatenatedStr << endl;

        delete[] copiedStr;
        delete[] concatenatedStr;

        cout << endl;
    }

    return 0;
}
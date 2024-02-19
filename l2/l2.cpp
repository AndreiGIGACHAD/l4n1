#include <iostream>
#include <cstring>

class Stroka {
    char str[80];

    int length1(const char* str) const {
        int length = 0;
        while (*str != '\0') {
            length++;
            str++;
        }
        return length;
    }

    char* copyString(const char* src) {
        int length = length1(src) + 1;
        char* dest = new char[length];
        char* ptr = dest;
        while (*src) {
            *ptr++ = *src++;
        }
        *ptr = '\0';
        return dest;
    }

public:
    Stroka(const char*);
    Stroka();
    Stroka(const Stroka&);
    Stroka& operator=(const Stroka&);
    Stroka operator+(const Stroka&);
    bool operator==(const Stroka&);
    int dlina();
    void vvod();
    void vyvod();
};

Stroka::Stroka(const char* string) {
    char* copiedStr = copyString(string);
    strcpy_s(str, copiedStr);
    delete[] copiedStr;
}

Stroka::Stroka() {
    str[0] = '\0'; // initializing with empty string
}

Stroka::Stroka(const Stroka& s) {
    char* copiedStr = copyString(s.str);
    strcpy_s(str, copiedStr);
    delete[] copiedStr;
}

Stroka& Stroka::operator=(const Stroka& s) {
    if (this != &s) {
        char* copiedStr = copyString(s.str);
        strcpy_s(str, copiedStr);
        delete[] copiedStr;
    }
    return *this;
}

Stroka Stroka::operator+(const Stroka& s) {
    char* concatenatedStr = new char[length1(str) + length1(s.str) + 1];
    strcpy_s(concatenatedStr, length1(str) + 1, str);
    strcat_s(concatenatedStr, length1(str) + length1(s.str) + 1, s.str);
    Stroka result(concatenatedStr);
    delete[] concatenatedStr;
    return result;
}

bool Stroka::operator==(const Stroka& s) {
    return (strcmp(str, s.str) == 0);
}

int Stroka::dlina() {
    return length1(str);
}

void Stroka::vvod() {
    std::cin >> str;
}

void Stroka::vyvod() {
    std::cout << str;
}

int main() {
    Stroka sl("qwert"), s3, s4(sl), s5;
    s3.vvod();
    s3 = s3 + Stroka("asdfg");
    s3.vyvod();
    std::cout << std::endl;
    s5 = sl + s3 + s4;
    std::cout << "длина s5 = " << s5.dlina() << std::endl;
    s5.vyvod();
    std::cout << std::endl;
    if (sl == s5)
        std::cout << "строки s1 и s5 равны";
    else if (sl == s4)
        std::cout << "строки s1 и s4 равны";

    return 0;
}

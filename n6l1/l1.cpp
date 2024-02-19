#include <iostream>
#include <cstring>

class Stroka {
    char str[80];
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
    strcpy_s(str, string);
}

Stroka::Stroka() {
    str[0] = '\0'; // initializing with empty string
}

Stroka::Stroka(const Stroka& s) {
    strcpy_s(str, s.str);
}

Stroka& Stroka::operator=(const Stroka& s) {
    strcpy_s(str, s.str);
    return *this;
}

Stroka Stroka::operator+(const Stroka& s) {
    strcat_s(str, s.str);
    return *this;
}

bool Stroka::operator==(const Stroka& s) {
    return (strcmp(str, s.str) == 0);
}

int Stroka::dlina() {
    return static_cast<int>(strlen(str)); // casting size_t to int
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

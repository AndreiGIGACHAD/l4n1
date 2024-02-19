#include <iostream>
#include <cstring>

class Stroka {
    char* str;

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
    // �����������, ��������� ��������� ������ � �������������� ��������� ������� ������������ ������
    Stroka(int size) {
        str = new char[size];
        str[0] = '\0'; // �������������� ������ ������ �������
    }

    Stroka(const char*);
    Stroka();
    Stroka(const Stroka&);
    Stroka& operator=(const Stroka&);
    Stroka operator+(const Stroka&);
    bool operator==(const Stroka&);
    int dlina();
    void vvod();
    void vyvod();

    // ���������� ��� ������������ ���������� ������������ ������
    ~Stroka() {
        delete[] str;
    }
};

Stroka::Stroka(const char* string) {
    char* copiedStr = copyString(string);
    str = copiedStr;
}

Stroka::Stroka() {
    str = new char[1]; // �������� ������ ��� ������ ������� (������� ������ ��� ������ ������)
    str[0] = '\0'; // initializing with empty string
}

Stroka::Stroka(const Stroka& s) {
    char* copiedStr = copyString(s.str);
    str = copiedStr;
}

Stroka& Stroka::operator=(const Stroka& s) {
    if (this != &s) {
        char* copiedStr = copyString(s.str);
        delete[] str; // ����������� ������� ������ ����� ������������� ������ ��������
        str = copiedStr;
    }
    return *this;
}

Stroka Stroka::operator+(const Stroka& s) {
    int totalLength = length1(str) + length1(s.str);
    char* concatenatedStr = new char[totalLength + 1];
    strcpy_s(concatenatedStr, totalLength + 1, str);
    strcat_s(concatenatedStr, totalLength + 1, s.str);
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
    Stroka sl("qwert"), s3, s4(sl), s5(100); // ������� ��������� � �������� 100
    s3.vvod();
    s3 = s3 + Stroka("asdfg");
    s3.vyvod();
    std::cout << std::endl;
    s5 = sl + s3 + s4;
    std::cout << "����� s5 = " << s5.dlina() << std::endl;
    s5.vyvod();
    std::cout << std::endl;
    if (sl == s5)
        std::cout << "������ s1 � s5 �����";
    else if (sl == s4)
        std::cout << "������ s1 � s4 �����";

    return 0;
}

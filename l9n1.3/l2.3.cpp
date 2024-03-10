#include <iostream>
#include <cstring>
using namespace std;

template <class T>
T getmax(T t1, T t2) {
    // ¬озвращает большее из двух параметров
    return t1 > t2 ? t1 : t2;
}

template <class T>
T getmax(T t[], size_t size) {
    T retval = t[0];
    for (size_t i = 0; i < size; i++) {
        if (t[i] > retval) {
            retval = t[i];
        }
    }
    return retval;
}

char* getmax(char* s1, char* s2) {
    // ¬озвращает строку, котора€ лексикографически больше
    return strcmp(s1, s2) > 0 ? s1 : s2;
}

int main() {
    int i1 = 3, i2 = 5;
  const  char* s1 = "строка1";
  const  char* s2 = "строка2";

    cout << "max int - " << getmax(i1, i2) << endl;
    cout << "max str = " << getmax(s1, s2) << endl;

    return 0;
}
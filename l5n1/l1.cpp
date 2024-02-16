#include <stdio.h>

int main() {
    char ch, name[50];
    FILE* in;

    printf("Enter the file name to view: ");
    scanf_s("%s", name, sizeof(name));

    if (fopen_s(&in, name, "r") != 0) {
        printf("Файл %s не открыт\n", name);
        return 1;
    }

    while ((ch = getc(in)) != EOF) {
        putchar(ch);
    }

    fclose(in);
    return 0;
}
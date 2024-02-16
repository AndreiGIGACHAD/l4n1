#include <stdio.h>
#include <ctype.h> 

int main() {
    char ch, name[50];
    FILE* in;
    int empty_count = 0, non_empty_count = 0;

    printf("Enter the file name to view: ");
    scanf_s("%s", name, sizeof(name));

    if (fopen_s(&in, name, "r") != 0) {
        printf("Файл %s не открыт\n", name);
        return 1;
    }

    while ((ch = getc(in)) != EOF) {
        if (isspace(ch) || ch == '\a') {
            empty_count++;
        }
        else {
            non_empty_count++;
        }
        putchar(ch);
    }

    fclose(in);

    printf("\nNumber of 'empty' characters: %d\n", empty_count);
    printf("The number of 'non-empty' characters: %d\n", non_empty_count);

    return 0;
}
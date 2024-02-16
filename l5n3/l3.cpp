#include <stdio.h>
#include <string.h>

int searchSubstring(const char* substring, FILE* file) {
    char line[1000];
    int found = 0;

    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, substring)) {
            found = 1;
            break;
        }
    }

    return found;
}

void writeResultsToFile(int found, const char* substring) {
    FILE* out;

    if (fopen_s(&out, "search_results.txt", "w") != 0) {
        printf("Failed to create a file to record the results.\n");
        return;
    }

    if (found) {
        fprintf(out, "Подстрока \"%s\" found in a text file.\n", substring);
    }
    else {
        fprintf(out, "Подстрока \"%s\"was not found in the text file.\n", substring);
    }

    fclose(out);
}

int main() {
    char name[50], substring[100];
    FILE* in;

    printf("Enter the file name to search for: ");
    scanf_s("%s", name, sizeof(name));

    printf("Enter a substring to search for: ");
    scanf_s("%s", substring, sizeof(substring));

    if (fopen_s(&in, name, "r") != 0) {
        printf("Файл %s no open\n", name);
        return 1;
    }

    int found = searchSubstring(substring, in);
    fclose(in);

    writeResultsToFile(found, substring);

    printf("The search results are recorded in a file search_results.txt\n");

    return 0;
}
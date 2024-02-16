#include <stdio.h>
#include <string.h>

int main() {
    FILE* file;
    char filename[100];
    char line[1000];
    char page_number[10];
    char* ptr;

    printf("Enter the filename: ");
    scanf_s("%s", filename, sizeof(filename));

    if (fopen_s(&file, filename, "r") != 0) {
        printf("Error opening the file.\n");
        return 1;
    }

    while (fgets(line, sizeof(line), file)) {
        if (sscanf_s(line, "%[^0-9]%s", page_number, sizeof(page_number), line, sizeof(line)) == 2) {
            line[strcspn(line, "\n")] = '\0';
            while (fgets(line, sizeof(line), file)) {
                if (strchr(line, '\f')) {
                    fseek(file, -(int)strlen(line), SEEK_CUR);
                    break;
                }
            }
            ptr = strrchr(line, '\f');
            if (ptr != NULL) {
                ptr++;
                strcpy_s(ptr, sizeof(line) - (ptr - line), page_number);
            }
        }
    }

    fclose(file);

    if (fopen_s(&file, filename, "w") != 0) {
        printf("Error opening the file for writing.\n");
        return 1;
    }

    rewind(file);
    while (fgets(line, sizeof(line), file)) {
        fprintf(file, "%s", line);
    }

    fclose(file);

    printf("File processing completed.\n");

    return 0;
}
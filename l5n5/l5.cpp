#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char encryptChar(char ch, const char* key) {
    static int keyIndex = 0;
    char encryptedChar = ch ^ key[keyIndex];
    keyIndex = (keyIndex + 1) % strlen(key);
    return encryptedChar;
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        printf("Usage: %s <input_file> <output_file> <encryption_key>\n", argv[0]);
        return 1;
    }

    FILE* inputFile;
    if (fopen_s(&inputFile, argv[1], "r") != 0) {
        printf("Error opening input file.\n");
        return 1;
    }

    FILE* outputFile;
    if (fopen_s(&outputFile, argv[2], "w") != 0) {
        printf("Error opening output file.\n");
        fclose(inputFile);
        return 1;
    }

    const char* key = argv[3];

    int ch;
    while ((ch = fgetc(inputFile)) != EOF) {
        char encryptedChar = encryptChar(ch, key);
        fputc(encryptedChar, outputFile);
    }

    fclose(inputFile);
    fclose(outputFile);

    printf("File encrypted successfully.\n");

    return 0;
}
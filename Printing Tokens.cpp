#include <stdio.h>
#include <string.h>

int main() {
    char str[1000];

    // Read the entire line (including spaces)
    fgets(str, sizeof(str), stdin);

    // Remove newline character if present
    str[strcspn(str, "\n")] = '\0';

    // Tokenize the string using space as delimiter
    char *token = strtok(str, " ");

    while (token != NULL) {
        printf("%s\n", token);
        token = strtok(NULL, " ");
    }

    return 0;
}


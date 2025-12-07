#include <stdio.h>

int main() {
    char s[100];

    // Read the input string
    fgets(s, sizeof(s), stdin);

    // Print required output
    printf("Hello, World!\n");
    printf("%s", s);

    return 0;
}

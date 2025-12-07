#include <stdio.h>

int main() {
    char ch;
    char s[100];
    char sen[200];

    // Read a single character
    scanf("%c", &ch);

    // Read a string (no spaces)
    scanf("%s", s);

    // To handle the leftover newline
    scanf("\n");

    // Read a full sentence (with spaces)
    scanf("%[^\n]%*c", sen);

    // Print output
    printf("%c\n", ch);
    printf("%s\n", s);
    printf("%s\n", sen);

    return 0;
}

#include <stdio.h>
#include <string.h>

int main() {
    char str[1000];
    int freq[10] = {0};  // Array to store frequency of digits 0-9

    // Read the input string
    scanf("%s", str);

    // Traverse the string
    for(int i = 0; str[i] != '\0'; i++) {
        if(str[i] >= '0' && str[i] <= '9') {
            freq[str[i] - '0']++;  // Increment the count for the digit
        }
    }

    // Print the frequencies
    for(int i = 0; i < 10; i++) {
        printf("%d ", freq[i]);
    }

    return 0;
}


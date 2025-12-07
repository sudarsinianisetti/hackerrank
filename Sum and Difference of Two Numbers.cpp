#include <stdio.h>

int main() {
    int a, b;
    float x, y;

    // Input two integers
    scanf("%d %d", &a, &b);

    // Input two floats
    scanf("%f %f", &x, &y);

    // Print sum and difference of integers
    printf("%d %d\n", a + b, a - b);

    // Print sum and difference of floats (1 decimal place)
    printf("%.1f %.1f\n", x + y, x - y);

    return 0;
}


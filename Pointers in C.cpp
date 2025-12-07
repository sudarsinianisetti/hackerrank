#include <stdio.h>
#include <stdlib.h>   // for abs()

void update(int *a, int *b) {
    int sum = *a + *b;
    int diff = abs(*a - *b);

    *a = sum;
    *b = diff;
}

int main() {
    int a, b;

    scanf("%d", &a);
    scanf("%d", &b);

    update(&a, &b);

    printf("%d\n", a);
    printf("%d\n", b);

    return 0;
}


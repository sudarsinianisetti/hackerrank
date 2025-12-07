#include <stdio.h>

// Recursive function to calculate nth term
int nth_term(int n, int a, int b, int c) {
    if(n == 1) return a;       // Base case: 1st term
    if(n == 2) return b;       // Base case: 2nd term
    if(n == 3) return c;       // Base case: 3rd term
    return nth_term(n-1, a, b, c) + nth_term(n-2, a, b, c) + nth_term(n-3, a, b, c);
}

int main() {
    int n, a, b, c;
    scanf("%d", &n);           // Read n
    scanf("%d %d %d", &a, &b, &c); // Read first three terms
    
    printf("%d\n", nth_term(n, a, b, c)); // Print nth term
    return 0;
}


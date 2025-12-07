#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* compare function for qsort */
int cmp(const void *a, const void *b) {
    const char *s1 = *(const char **)a;
    const char *s2 = *(const char **)b;
    return strcmp(s1, s2);
}

/* swap two pointers (strings) */
void swap(char **a, char **b) {
    char *temp = *a;
    *a = *b;
    *b = temp;
}

/* generates next lexicographical permutation */
int next_permutation(int n, char **s) {

    int i = n - 2;

    /* Step 1: find first decreasing element from right */
    while (i >= 0 && strcmp(s[i], s[i + 1]) >= 0) {
        i--;
    }

    if (i < 0)
        return 0;   // no more permutations

    /* Step 2: find element just larger than s[i] */
    int j = n - 1;
    while (strcmp(s[j], s[i]) <= 0) {
        j--;
    }

    /* Step 3: swap them */
    swap(&s[i], &s[j]);

    /* Step 4: reverse the part after i */
    int left = i + 1;
    int right = n - 1;

    while (left < right) {
        swap(&s[left], &s[right]);
        left++;
        right--;
    }

    return 1;
}

/* print current permutation */
void print_array(int n, char **s) {
    for (int i = 0; i < n; i++) {
        printf("%s", s[i]);
        if (i != n - 1)
            printf(" ");
    }
    printf("\n");
}

int main()
{
	char **s;
	int n;
	scanf("%d", &n);
	s = calloc(n, sizeof(char*));
	for (int i = 0; i < n; i++)
	{
		s[i] = calloc(11, sizeof(char));
		scanf("%s", s[i]);
	}
	do
	{
		for (int i = 0; i < n; i++)
			printf("%s%c", s[i], i == n - 1 ? '\n' : ' ');
	} while (next_permutation(n, s));
	for (int i = 0; i < n; i++)
		free(s[i]);
	free(s);
	return 0;
}

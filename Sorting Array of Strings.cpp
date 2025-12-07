#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>

/* 1. Lexicographically increasing */
int lexicographic_sort(const char* a, const char* b) {
    return strcmp(a, b);
}

/* 2. Lexicographically decreasing */
int lexicographic_sort_reverse(const char* a, const char* b) {
    return strcmp(b, a);
}

/* Helper: count distinct characters in a string */
int count_distinct(const char* s) {
    int f[26] = {0};
    int count = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        if (f[s[i] - 'a'] == 0) {
            f[s[i] - 'a'] = 1;
            count++;
        }
    }
    return count;
}

/* 3. Sort by number of distinct characters */
int sort_by_number_of_distinct_characters(const char* a, const char* b) {
    int da = count_distinct(a);
    int db = count_distinct(b);

    if (da == db)
        return strcmp(a, b);   // tie breaker
    return da - db;
}

/* 4. Sort by length of strings */
int sort_by_length(const char* a, const char* b) {
    int la = strlen(a);
    int lb = strlen(b);

    if (la == lb)
        return strcmp(a, b);  // tie breaker
    return la - lb;
}

/* STRING SORT FUNCTION */
void string_sort(const char **arr, const int cnt,
                 int (*cmp_func)(const char* a, const char* b)) {

    for (int i = 0; i < cnt - 1; i++) {
        for (int j = i + 1; j < cnt; j++) {
            if (cmp_func(arr[i], arr[j]) > 0) {
                const char* temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() 
{
    int n;
    scanf("%d", &n);
  
    char** arr;
	arr = (char**)malloc(n * sizeof(char*));
  
    for(int i = 0; i < n; i++){
        *(arr + i) = malloc(1024 * sizeof(char));
        scanf("%s", *(arr + i));
        *(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
    }
  
    string_sort(arr, n, lexicographic_sort);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, lexicographic_sort_reverse);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");

    string_sort(arr, n, sort_by_length);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);    
    printf("\n");

    string_sort(arr, n, sort_by_number_of_distinct_characters);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");
}

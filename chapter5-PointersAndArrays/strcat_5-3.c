#include <stdio.h>

void my_strcat(char *s, char *t);

int main() {
    char a[200] = "I love";
    char *b = " you";
    printf("%s\n", a);
    my_strcat(a, b);
    printf("%s\n", a);
    return 0;
}

void my_strcat(char *s, char *t) {
    char c;
    while (c = *s++)
        ;
    s--;
    while (*s++ = *t++)
        ;
}
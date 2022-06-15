#include <stdio.h>

int my_strlen(char *);

int main(void) {
    char *s = "salhqgw";
    printf("Initial address: %p\n", s);

    printf("%d\n", my_strlen(s));

    printf("Final address: %p\n", s);
    return 0;
}

int my_strlen(char *s) {
    int n;
    for (n = 0; *s != '\0'; s++)
        n++;
    return n;
}
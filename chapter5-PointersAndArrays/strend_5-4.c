#include <stdio.h>

int strend(char *s, char *t);

int main() {
    char *a = "hello word!";
    char *b = "rd!";
    printf("%d\n", strend(a, b));
    return 0;
}

int strend(char *s, char *t) {
    int i = 0;
    char ch;
    char *tmp = t;
    while ((ch = *tmp++)) i++;
    while (*(s + i)) s++;
    while (*s)
        if (*s++ != *t++)
            return 0;
    return 1;
}
#include<stdio.h>

int main() {
    int ch;
    while((ch = getchar()) != EOF) {
        if (ch == ' ') {
            while((ch = getchar()) == ' ');
            putchar(' ');
        } else {
            putchar(ch);
        }
    }
    return 0;
}
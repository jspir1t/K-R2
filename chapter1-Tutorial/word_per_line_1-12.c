#include<stdio.h>

#define IN 1
#define OUT 0

int main() {
    int state, ch;
    state = OUT;
    while((ch = getchar()) != EOF) {
        if (ch == '\n' || ch == '\t' || ch == ' ') {
            state = OUT;
        } else {
            if (state == OUT) {
                putchar('\n');
                state = IN;
            }
            putchar(ch);
        }
    }
    return 0;
}
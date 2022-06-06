#include<stdio.h>

#define IN 1
#define OUT 0

int main() {
    int c, nl, nw, nc, state;
    state = OUT;
    // sequential assignment from right to left
    nl = nw = nc = 0;
    while((c = getchar()) != EOF) {
        ++nc;
        if (c == '\n') {
            ++nl;
        }
        if (c == '\n' || c == ' ' || c == '\t') {
            state = OUT;
        } else if (state == OUT) {
            state = IN;
            ++nw;
        }
    }
    printf("word number = %d, line number = %d and character number = %d\n", nw, nl, nc);
    return 0;
}
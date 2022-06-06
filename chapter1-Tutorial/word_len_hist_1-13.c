#include<stdio.h>

#define MAX_LEN 10
#define OUT 0
#define IN 1

int main() {
    int c, state;
    state = OUT;
    int wl[MAX_LEN + 1];
    for (int i = 0; i <= MAX_LEN; i++)
        wl[i] = 0;

    int len = 0;
    while((c = getchar()) != EOF) {
        ++len;
        if (c == '\n' || c == '\t' || c == ' ') {
            state = OUT;
            --len;
        }
        else if (state == OUT) {
            if (len != 0 && len <= MAX_LEN) {
                ++wl[len];
            }
            state = IN;
            len = 0;
        }
    }
    for(int i = 1; i <= MAX_LEN; ++i){
        printf("|%2d| ", i);
        for(int j = 0; j < wl[i]; ++j)
            putchar('*');
        putchar('\n');
    }
    return 0;
}
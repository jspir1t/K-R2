#include<stdio.h>

#define SIZE 26

int main() {
    int c;
    int cf[SIZE];
    for (int i = 0; i <= SIZE; i++)
        cf[i] = 0;

    while((c = getchar()) != EOF) {
        if (c >= 'a' && c <= 'z') {
            cf[c-'a']++;
        }
    }
    for(int i = 0; i < SIZE; ++i){
        putchar('|');
        putchar(i + 'a');
        putchar('|');
        for(int j = 0; j < cf[i]; ++j)
            putchar('*');
        putchar('\n');
    }
    return 0;
}
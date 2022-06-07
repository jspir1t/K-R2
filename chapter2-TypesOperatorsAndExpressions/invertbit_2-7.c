#include <stdio.h>

int invert(int x, int p, int n) {
    int mask = ((~(~0 << n)) << p - n);
    printf("%d\n", mask);
    return x ^ mask;
}

int main() {
    printf("%d\n", invert(90, 4, 3));
    return 0;
}
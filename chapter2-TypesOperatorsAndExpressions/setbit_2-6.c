#include <stdio.h>

int setbits(int x, int p, int n, int y) {
    unsigned int mask = ~(~0 << n);
    return (x & ~(mask << p + 1 - n)) | ((y & mask << p + 1 - n));
}

int main() {
    int x = 9713;  // 0010 0101 1111 0001
    int y = 3500;  // 0000 1101 1010 1100

    printf("Setbit result: %d\n", setbits(x, 11, 4, y));  // expecting 0010 1100 1111 0001 - 11761

    return 0;
}
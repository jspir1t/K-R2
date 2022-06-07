#include<stdio.h>

int main() {
    int v = 0xff773311;
    int ans = 0;
    while(v != 0) {
        v &= v - 1;
        ++ans;
    }
    printf("bit count = %d\n", ans);
    return 0;
}
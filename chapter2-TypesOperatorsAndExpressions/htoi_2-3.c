#include <stdio.h>

int htoi(char s[]);

int main() {
    int ans = 0;
    char *c = "0x1c";
    printf("%d\n", htoi(c));
    return 0;
}

int htoi(char s[]) {
    int i, n;
    i = n = 0;
    if (s[0] == '\0') return 0;
    if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X')) i = 2;
    while (s[i] != '\0') {
        char ch = s[i];
        if (ch >= '0' && ch <= '9') {
            n = n * 16 + (ch - '0');
        } else if (ch >= 'a' && ch <= 'f') {
            n = n * 16 + (ch - 'a' + 10);
        } else if (ch >= 'A' && ch <= 'F') {
            n = n * 16 + (ch - 'A' + 10);
        } else {
            return -1;
        }
        ++i;
    }
    return n;
}
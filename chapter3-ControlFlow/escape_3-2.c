#include <stdio.h>
#include <string.h>

void escape(char *, char *);
void unescape(char *, char *);

int main() {
    char *s = "\tHello,\n\tWorld! Mistakee\t";
    char t[1000];
    escape(s, t);
    printf("%s\n", s);
    printf("%s\n", t);

    char g[1000];
    unescape(g, t);
    printf("%s\n", t);
    printf("g = %s\n", g);
    return 0;
}

void escape(char *s, char *t) {
    int i = 0, j = 0;
    while (s[i] != '\0') {
        switch (s[i]) {
            case '\n':
                t[j++] = '\\';
                t[j++] = 'n';
                break;
            case '\t':
                t[j++] = '\\';
                t[j++] = 't';
                break;
            default:
                t[j++] = s[i];
                break;
        }
        i++;
    }
    t[j] = '\0';
}

void unescape(char *s, char *t) {
    int i = 0, j = 0;
    while (t[j] != '\0') {
        switch (t[j]) {
            case '\\':
                // printf("gg");
                switch (t[++j]) {
                    case 'n':
                        s[i] = '\n';
                        break;
                    case 't':
                        s[i] = '\t';
                        break;
                    default:
                        s[i] = '\\';
                        break;
                }
                break;
            default:
                s[i] = s[j];
                break;
        }
        i++;
        j++;
    }
    s[i] = t[j];
}
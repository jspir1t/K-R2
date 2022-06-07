//   for(i=0; i<lim-1 && (c=getchar()) != '\n' && c != EOF; ++i)
//     s[i] = c;

#include <stdio.h>

int main() {
    int i = 0;
    int c;
    while (i < 999) {
        if ((c == getchar()) != '\n') {
            if (c != EOF) {
                // do it
            } else {
                break;
            }
        } else {
            break;
        }
    }
    for (i = 0; ((i < 999) + ((c = getchar()) != '\n') + (c != EOF)) == 3; ++i)
        // do its
        ;
}
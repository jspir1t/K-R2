#include<stdio.h>

int main() {
  int line_cnt = 0, blank_cnt = 0, tab_cnt = 0;
  int ch;
  while( (ch = getchar()) != EOF ) {
    if (ch == ' ') {
      blank_cnt++;
    } else if (ch == '\n') {
      line_cnt++;
    } else if (ch == '\t') {
      tab_cnt++;
    }
  }
  printf("line cnt = %d, blank cnt = %d, tab cnt = %d\n", line_cnt, blank_cnt, tab_cnt);
  return 0;
}

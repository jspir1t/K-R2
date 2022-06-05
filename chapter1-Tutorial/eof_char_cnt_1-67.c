#include<stdio.h>

// EOF could be produced in ubuntu by CTRL+D
int main(){
  printf("EOF = %d\n", EOF);
  int c;
  // compact way combines the assignment with comparison
  // Notice != is higher than = in terms of priority, thus the parentheses are required
  // If the parentheses are removed, c will be either 0 or 1 in ASCII, no matter printf or putchar will generate invisible output in the console(try it you will see
  while(c = getchar() != EOF) {
    // The printf function will print ASCII code
    //printf("%d\n", c);
    // The putchar will put the character into stdout and print in screen
    putchar(c);
  }
  return 0;
}

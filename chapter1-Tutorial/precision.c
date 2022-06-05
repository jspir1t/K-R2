#include<stdio.h>

int main(){
  int i = 123214123;
  float f = 21312.211512512;
  printf("Original: i = %d and f = %f\n", i, f);
  // The %12d indicate at least 12 wide for the integer
  // The %9.15f indicate at least 9 wide, and keep 15 characters after the decimal point(padding with 0)
  // Notice the wide take decimal point '.' into consideration 
  printf("Conversion: i = %12d and f = %9.15f\n", i, f);
  return 0;
}

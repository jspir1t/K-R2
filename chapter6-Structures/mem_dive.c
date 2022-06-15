#include <stdio.h>

void modify_char_arr(char arr[]) {
    arr[0] = '#';
    printf("Array address passed in: %p\n", arr);
}

struct my_struct {
    char arr[16];
};

typedef struct my_struct my_struct;

void modify_struct_arr(my_struct ms) {
    ms.arr[0] = 'm';
    printf("Array address inside the passed-in struct: %p\n", ms.arr);
}

int main() {
    char ch[] = "gg";
    printf("Original: %s\n", ch);
    printf("Array address of original array: %p\n", ch);
    modify_char_arr(ch);
    printf("After modifying: %s\n\n", ch);

    my_struct s = {"hello world"};
    printf("Original: %s\n", s.arr);
    printf("Array address inside the original struct: %p\n", s.arr);
    modify_struct_arr(s);
    printf("After modifying: %s\n", s.arr);
    return 0;
}
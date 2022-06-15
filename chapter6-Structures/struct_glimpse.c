#include <stdio.h>

struct myStruct {
    // a plain variable in stack
    int age;
    // an int pointer
    int *weight;
    // a character array
    char name[10];
    // a char pointer
    char *gender;
    // a pointer to a char pointer
    char **place;
};

typedef struct myStruct myStruct;

void func1(myStruct s) {
    // This age is copied from the main stack to func1 stack, not reflect
    s.age = 23;
    // reflect, modify by pointer
    *(s.weight) = 70;
    // do not reflect, the array is copied within the struct to stack 
    // Notice a single char array passed could be modified
    s.name[0] = '#';
    printf("The address of the char array passed to function: %p\n", s.name);
    // reflect, create a variable 
    *(s.gender) = 'g';
    // reflect, create a string literal in code section, refered by s.place
    *(s.place) = "lh";
}

void func2(myStruct *s) {
    s->age = 25;
    *(s->weight) = 65;
    // this will reflect since it changes the second char of the string literal copied to main stack
    s->name[1] = 't';
    *(s->gender) = 'd';
    *(s->place) = "sc";
}

int main() {
    // temp is in stack
    char tmp = 'a';
    // pointer 'a' is in stack
    char *a = &tmp;
    printf("%c\n", *a);

    // weight is in stack
    int weight = 68;
    // "sh" is in the code text area
    // The place pointer is a char pointer pointing to a character.
    // The printf function with %s will print from the pointer until the zero value '\0'
    char *place = "sh";

    // "jingtong" is in the code text section.
    myStruct s = {24, &weight, "jingtong", &tmp, &place};
    printf("The address of the char array passed to function: %p\n", s.name);

    printf("Original: %d, %d, %s, %c, %s\n", s.age, *(s.weight), s.name, *(s.gender), *(s.place));
    func1(s);
    printf("Pass By Value: %d, %d, %s, %c, %s\n", s.age, *(s.weight), s.name, *(s.gender), *(s.place));
    func2(&s);
    printf("Pass By Pointer: %d, %d, %s, %c, %s\n", s.age, *(s.weight), s.name, *(s.gender), *(s.place));

    // string literal "test" in data section, which is read only
    char *test = "test";
    // access it will result in segmentation falut
    *(test + 1) = 't';
    printf("%s\n", test);
}
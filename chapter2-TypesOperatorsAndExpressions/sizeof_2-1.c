#include <stdio.h>

float getFloat(char sign, unsigned char exp, unsigned mantissa);
double getDouble(char sign, unsigned short exp, unsigned long long mantissa);

int main(void) {
    printf("Signed char[%d to %d]\n", ~((unsigned char)~0 >> 1), (unsigned char)~0 >> 1);
    printf("Unsigned char[0 to %u]\n", (unsigned char)~0);

    printf("Size of short is %ld bytes\n", sizeof(short));
    printf("Signed short[%d to %d]\n", ~((unsigned short)~0 >> 1), (unsigned short)~0 >> 1);
    printf("Unsigned short[0 to %u]\n", (unsigned short)~0);

    printf("Signed int[%d to %d]\n", ~(~0U >> 1), ~0U >> 1);
    printf("Unsigned int[0 to %u]\n", ~0U);

    printf("Signed long[%ld to %ld]\n", ~(~0UL >> 1), ~0UL >> 1);
    printf("Unsigned long[0 to %lu]\n", ~0UL);

    printf("Signed long long[%lld to %lld]\n", ~(~0ULL >> 1), ~0ULL >> 1);
    printf("Unsigned long long[0 to %llu]\n", ~0ULL);

    printf("Float[%g to %g]\n", getFloat(1, 0, 1), getFloat(0, ~0 - 1, ~0));

    printf("Double[%g to %g]\n", getDouble(1, 0, 1), getDouble(0, ~0 - 1, ~0));

    return 0;
}

float getFloat(char sign, unsigned char exp, unsigned mantissa) {
    unsigned f = (unsigned)(sign != 0) << 31 | (unsigned)exp << 23 | mantissa & 0x7FFFFF;
    return *((float *)&f);
}

double getDouble(char sign, unsigned short exp, unsigned long long mantissa) {
    unsigned long long d = (unsigned long long)(sign != 0) << 63 | (unsigned long long)(exp & 0x7FF) << 52 | mantissa & 0xFFFFFFFFFFFFF;
    return *((double *)&d);
}
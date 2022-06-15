/*
e.g. "12.345 e -5.337" = 0.00005681867
*/

#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

double myatof(char s[]);

int main(void) {
    char num[] = "1288644.345e-5.337";

    printf("%.12f\n", myatof(num));

    return 0;
}

double myatof(char s[]) {
    double val, power, exponent;
    int i, sign;
    for (i = 0; isspace(s[i]); i++)
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }
    for (; isspace(s[i]); i++) 
        ;

    if ((s[i] != '\0') && (tolower(s[i++]) == 'e'))
        exponent = myatof(&s[i]);                   
    else
        exponent = 0.0;

    return (sign * val / power) * pow(10.0, exponent);
}

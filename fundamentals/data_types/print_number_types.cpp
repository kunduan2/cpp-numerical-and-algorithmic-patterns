/* Print all types of numbers */

#include<iostream>
#include <cstdio>
#include<cmath>

void print_number_types(){
    int i = 42;
    unsigned int ui = 42u;
    long l = 42l;
    unsigned long ul = 42ul;
    long long ll = 42ll;
    unsigned long long ull = 42ull;

    float f = 3.007f;
    double d = 3.007;
    long double ld = 3.007L;

    char c = 'A';
    signed char sc = -5;
    unsigned char uc = 250;

    printf("int                : %d\n", i);
    printf("unsigned int       : %u\n", ui);
    printf("long               : %ld\n", l);
    printf("unsigned long      : %lu\n", ul);
    printf("long long          : %lld\n", ll);
    printf("unsigned long long : %llu\n", ull);

    printf("float              : %f\n", f);   // promoted to double
    printf("double             : %f\n", d);
    printf("long double        : %Lf\n", ld);

    printf("char               : %c\n", c);
    printf("signed char        : %hhd\n", sc);
    printf("unsigned char      : %hhu\n", uc);

    // If you want hex / scientific / precision
    printf("\nIf you want hex / scientific / precision");
    printf("hex int     : %#x\n", i);
    printf("scientific  : %.3e\n", d);
    printf("precision   : %.2f\n", d);

     // Ceil and floor
    printf("\nCeil and Floor. Note: they return floor NOT int!");
    double x = 3.3;
    printf("ceil(x=%.1f)  : %.1f\n", x, ceil(x));
    printf("Floor(x=%.1f)  : %.2f\n", x,  floor(x));
    printf("Round(x=%.1f)  : %.2f\n", x, round(x));

    // double to int and similar
    printf("\nOne data type to another\n");
    x= 3.33567; // double
    printf("int(x = 3.33567)  : %d\n", (int)x);
    printf("double(5)  : %.5f\n", (double)5);

}

int main(){
    print_number_types();
}

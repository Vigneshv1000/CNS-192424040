#include <stdio.h>
#include <math.h>

int main()
{
    double total, unique;

    total = 1;

    for(int i = 1; i <= 25; i++)
        total *= i;

    unique = total / (25 * 24 * 2);

    printf("Total possible keys = 25! = %.0f\n", total);
    printf("Approximate power of 2 = 2^%.2f\n",
           log(total) / log(2));

    printf("Effectively unique keys = %.0f\n", unique);
    printf("Unique keys approximately = 2^%.2f\n",
           log(unique) / log(2));

    return 0;
}
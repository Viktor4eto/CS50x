#include <stdio.h>
#include <cs50.h>
#include <math.h>

int S = 0;
int n;

do
{
     n = get_int("n = \n");
} while (n < 0);

printf("%i", n);
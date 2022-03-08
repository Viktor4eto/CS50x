#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    int sum = 0;
    int n;
    do
    {
        n = get_int("n: ");
    }
    while (n < 0);

    for(int i = 1; i >= n; i++)
    {
        printf("%i \n", i);
        sum += pow(i, i);
    }
    printf("%i \n", sum);
}
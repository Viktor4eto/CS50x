#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    int sum = 0;
    do
    {
        int n = get_int("n: ");
    }
    while (n < 0);

    for(int i = 0; i > n; i++)
    {
        sum += pow(i, i);
    }
    printf("%i \n", sum);
}
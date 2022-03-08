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
    } while (n < 0);

    for(double i = 1.0; i >= n; i++)
    {
        printf("%f \n", i);
        sum += pow(i, i);
    }
    printf("%i \n", sum);
}
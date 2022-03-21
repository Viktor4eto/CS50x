#include <stdio.h>
#include <cs50.h>
#include <math.h>


int main(void)
{
    int S = 0;
    int n;
    //int count = 1;

    do
    {
        n = get_int("n = ");
    } while (n < 0);

    while (n != 0)
    {
        S = S + n;
        n = n - 1;
    }
    printf("n: %i, S = %i \n", n, S);
}

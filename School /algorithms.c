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

    for (int i = 0; i < n; i++)
    {
        S = S + i;
    }
    printf("n: %i, S = %i \n", n, S);
}

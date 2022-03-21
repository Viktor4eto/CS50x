#include <stdio.h>
#include <cs50.h>
#include <math.h>


int main(void)
{
    int S = 0;
    int n;
    
    do
    {
        n = get_int("n = ");
    } while (n < 0);

    printf("%i", n);
}

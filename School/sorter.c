#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    int save;
    int c = get_int("c: ");
    int n[c];

    for (int i = 0; i < c; i++)
    {
        n[i] = get_int("n: ");
        //printf("\n");
    }


    for(int i = 0; i < c; i++)
    {
        for (int j = i + 1; j < c; j++)
        {
            if (n[i] > n[j])
            {
                save = n[i];
                n[i] = n[j];
                n[j] = save;
            }
        }
    }
    for (int i = 0; i < c; i++)
    {
        printf("%i \n", n[i]);
    }

}
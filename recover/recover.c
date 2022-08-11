#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argv[1] == NULL)
    {
        printf("Usage: ./recover IMAGE \n");
        return 1;
    }
    FILE *raw = fopen(argv[1], "r");

    while (feof(raw) == 0)
    {
        int i = 0;
        printf("works \n");

        if (i == 2)
        {
            break;
        }
        i++;
    }

    return 0;
}
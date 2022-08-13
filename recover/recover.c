#include <stdio.h>
#include <stdlib.h>

typedef uint8_t  BYTE;

int main(int argc, char *argv[])
{
    int buffer[512] = malloc(512*(sizeof(BYTE)))
    if (argv[1] == NULL)
    {
        printf("Usage: ./recover IMAGE \n");
        return 1;
    }
    FILE *raw = fopen(argv[1], "r");

    while (feof(raw) == 0)
    {
        fread()
    }

    return 0;
}
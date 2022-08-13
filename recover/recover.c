#include <stdio.h>
#include <stdlib.h>

typedef uint8_t  BYTE;

int main(int argc, char *argv[])
{
    if (argv[1] == NULL)
    {
        printf("Usage: ./recover IMAGE \n");
        return 1;
    }

    BYTE *buffer = malloc(512 * (sizeof(BYTE)));
    int JPEG_counter = 0; 

    if (buffer == NULL)
    {
        printf ("malloc has failed \n");
        free;
        return 2;
    }

    FILE *raw = fopen(argv[1], "r");

    while (feof(raw) == 0)
    {
        fread(buffer, sizeof(BYTE), 512, raw);

        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {

        }
    }

    return 0;
}
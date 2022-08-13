#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

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
    string filename;
    bool new = false;

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
            sprintf(filename, "%03i", JPEG_counter);
            //JPEG_counter++;
            FILE *current = fopen(filename, "w")
            fwrite (buffer, sizeof(BYTE), 512, current)

            while (!new)
            {
                fread(buffer, sizeof(BYTE), 512, raw);
    
                if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
                {
                    new = true;
                    break;
                }

                else
                {
                    fwrite (buffer, sizeof(BYTE), 512, current);
                }
            }
        }
    }

    return 0;
}
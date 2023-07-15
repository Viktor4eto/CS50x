#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <cs50.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if (argv[1] == NULL)
    {
        printf("Usage: ./recover IMAGE \n");
        return 1;
    }

    BYTE *buffer = malloc(512 * (sizeof(BYTE)));
    int JPEG_counter = 0;
    FILE *current;
    bool alreadyRead = false;
    bool new = false;

    if (buffer == NULL)
    {
        printf("malloc has failed \n");
        free(buffer);
        return 2;
    }

    FILE *raw = fopen(argv[1], "r");



    printf("File opened!\n");

    while (fread(buffer, 1, 512, raw) == 512)
    {

        printf("Enter \n");

        if ((buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0))
        {
            printf("Image \n");
            fclose(current);

            char *newFiles = malloc(3*sizeof(char));

            if (newFiles == NULL)
            {
                printf("malloc has failed \n");
                free(newFiles);
                return 3;
            }

            sprintf(newFiles, "%03i.jpg", JPEG_counter);
            JPEG_counter++;

            printf("Not made file \n");

            current = fopen(newFiles, "w");

            printf("Made file \n");

            free(newFiles);

            fwrite (buffer, 1, 512, current);

            printf("Things \n");

            }

            fwrite (buffer, 1, 512, current);


        }

    //fwrite (buffer, 1, 512, current);

    printf("Exit \n");

    free(buffer);

    return 0;
}
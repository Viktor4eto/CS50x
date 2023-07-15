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

    while (!feof(raw))
    {

        printf("Enter \n");

        //if(!alreadyRead){
            fread(buffer, 1, 512, raw);
        //}

        new = false;

        printf("fread \n");

        if ((buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0))
        {
            printf("Image \n");

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


            while (!new && !feof(raw))
            {
                printf("Loop 2 enter \n");

                fread(buffer, 1, 512, raw);

                if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
                {
                    new = true;
                    alreadyRead = true;
                    fseek(raw, -512, SEEK_CUR);
                    printf("Loop 2 exit \n");
                    break;
                }

                else
                {
                    fwrite (buffer, 1, 512, current);
                }


            }


        }
    }
    //fwrite (buffer, 1, 512, current);

    printf("Exit \n");

    free(buffer);

    return 0;
}
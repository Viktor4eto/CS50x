#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <cs50.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    //Checks if there is an inputted image
    if (argv[1] == NULL)
    {
        printf("Usage: ./recover IMAGE \n");
        return 1;
    }

    //Creates the buffer that will store the read bytes
    BYTE *buffer = malloc(512 * (sizeof(BYTE)));
    char newFiles[8];
    int JPEG_counter = 0;

    //Checks if malloc worked
    if (buffer == NULL)
    {
        printf("malloc has failed \n");
        free(buffer);
        return 2;
    }

    //Opens the file and creates a file that will store the images
    FILE *raw = fopen(argv[1], "r");
    FILE *current;

    bool found = false;

    //printf("File opened!\n");
    //Enters a loop that checks when there are enough bytes in the buffer
    while (fread(buffer, 1, 512, raw) == 512)
    {
        //Condition for a new image file
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            //printf("Image \n");
            if (found)
            {
                fclose(current);
            }

            //Handles the making of the new file name
            sprintf(newFiles, "%03i.jpg", JPEG_counter);

            JPEG_counter++;

            current = fopen(newFiles, "w");
            //printf("Made file \n");

            found = true;
        }

        if (found)
        {
            //printf("Wrote \n");
            fwrite(buffer, 1, 512, current);
        }

    }


    //printf("Exit \n");

    free(buffer);
    fclose(current);
    fclose(raw);

    return 0;
}
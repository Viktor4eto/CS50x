#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int rows;
    do
    {
        rows = get_int("Rows: ");
    }
    while (rows < 1 || rows > 8);
    printf("Rows are %i.\n", rows);

    for (int i = 0; i < rows; i++){
        for (int p = 0; p < rows; p++){
            printf("#");
        }
        printf("\n");
    }
}
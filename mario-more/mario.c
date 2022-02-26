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
    //printf("Rows are %i.\n", rows);
    //Index and change of rows
    for (int i = 0; i < rows; i++)
    {
        //Changing in a row
        for (int p = 0; p <= rows + 1 + i; p++)
        {
            //Outer pyramid
            if (i + rows + 1 >= p && rows < p)
            {
                printf("#");
            }
            //Inner pyramid
            else if (rows - i - 1 <= p && rows > p)
            {
                printf("#");
            }
            //Mid section
            else if (p == rows)
            {
                printf("  ");
            }
            //Spaces to reach the pyramids
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}
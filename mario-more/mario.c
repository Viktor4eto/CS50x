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
    for (int i = 0; i < rows; i++){
        for (int p = 0; p <= 2*rows+1; p++){
            if(i+rows+1 >= p && rows < p){
                printf("#");
            }
            else if(rows-i-1 <= p && rows > p){
                printf("#");
            }
            else if (p == rows){
                printf("  ");
            }
            else{
                printf(" ");
            }
        }
        printf("\n");
    }
}
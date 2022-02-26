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
    int count = 0;
    for (int i = 0; i < rows; i++){
        for (int p = rows; p >= 0; p--){
            if(p <= count){
                printf("#");
            }
            else{
                printf(" ");
            }
        }
        count++;
        printf("\n");
    }
}
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
        for (int p = 2*rows+1; p >= 0; p--){
            if(count >= p-rows-1 && p != rows && p > rows){
                printf("#");
            }
            else if (p <= count+rows && p != rows && count <= p-1){
                printf("#");
            }
            else if (p == rows){
                printf(".");
            }
            else{
                printf(" ");
            }
        }
        count++;
        printf("\n");
    }
}
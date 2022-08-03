#include <cs50.h>
#include <stdio.h>

int main (void)
{
    int arr[] = {5, 7, 3, 5, 4, 3, 9, 1, 2};

    for (int i = 0; i < 8; i++)
    {
        for (int j = i + 1; j < 9; j++)
        {
            if(arr[i] < arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    for (int i = 0; i < 9; i++)
    {
    printf("%i", arr[i]);
    }

    printf("\n");

    return 0;
}
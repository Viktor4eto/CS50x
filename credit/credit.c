#include <cs50.h>
#include <math.h>
#include <stdio.h>

//Counts the lenght of the long
int len(long long n)
{
    int count = 1;
    while (n > 10)
    {
        count++;
        n /= 10;
    }
    return count;
}

//Checks if the credit card is real or not
bool legit(long long n)
{
    //Checks if the value should be double or not
    bool is = false;
    int sum = 0;
    int save = 0;
    //printf("%i \n", len(n));
    //Goes through all numbers in the card
    for (int i = len(n); i > 0; i--)
    {
        //printf("n: %i \n", count);
        if (is == false)
        {
            sum += n % 10;
            is = true;
            n = n / 10;
            //printf("%i and %lld \n", sum, n);
        }
        else
        {
            if (n % 10 >= 5)
            {
                save = n % 10 * 2;
                sum += save % 10 + save / 10;
                //printf("%i and %lld \n", sum, n);
            }
            else
            {
                sum += n % 10 * 2;
                //printf("%i and %lld \n", sum, n);
            }
            n = n / 10;
            is = false;
        }
        //printf("%i and %lld %d \n", sum, n, is);
    }
    //What should be returned?
    if (sum % 10 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main(void)
{
    long long num = get_long("Credit card number: ");
    //printf("%f \n", floor(num/pow(10, 14)));
    //Main logic that differentaites
    if (legit(num))
    {
        if (floor(num / pow(10, 13)) == 34 || floor(num / pow(10, 13)) == 37)
        {
            printf("AMEX\n");
        }
        else if (floor(num / pow(10, 14)) == 51 || floor(num / pow(10, 14)) == 52 || floor(num / pow(10, 14)) == 53
                 || floor(num / pow(10, 14)) == 54 || floor(num / pow(10, 14)) == 55)
        {
            printf("MASTERCARD\n");
        }
        else if (floor(num / pow(10, 12)) == 4 || floor(num / pow(10, 15)) == 4)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}

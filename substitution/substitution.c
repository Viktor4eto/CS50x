#include <cs50.h>
#include <stdio.h>
#include <ctype.h>

char substitute(char x);

int main(int argc, string argv[])
{

}

char substitute(char x)
{
    int i = (int) x;
    char new;
    if (i > 64 && i < 91)
    {
        new = argv[1][i - 65]
    }
    else if (i > 140 && i < 173)
    {
        new = argv[1][i - 141]
    }
    return new; 
}
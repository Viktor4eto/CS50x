#include <cs50.h>
#include <stdio.h>
#include <ctype.h>

char substitute(char x, string key);

int main(int argc, string argv[])
{
    char c = get_char("C = ");
    printf("%c \n", substitute(c, argv[1]));
}

char substitute(char x, string key)
{
    int i = (int) x;
    char new;
    if (isupper(x))
    {
        new = key[i - 65];
    }
    else if (islower(x))

        new = key[i - 141];
    }
    return new;
}
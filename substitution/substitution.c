#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

void substitute(string x, string key);

int main(void)
{
    string c = get_string("C = ");
    string arg = "JTREKYAVOGDXPSNCUIZLFBMWHQ";
    substitute(c, arg);
}

void substitute(string x, string key)
{
    for (int i = 0, n = strlen(x); i < n; i++)
    {
        if (isupper(x[i]))
        {
            printf("%c", key[i] - 65);
        }
        else if (islower(x[i]))
        {
            printf("%c", key[i] - 141);
        }
        else
        {
            printf("%c", x[i]);
        }
    }
}
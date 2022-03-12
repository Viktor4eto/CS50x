#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

void substitute(string x, string key);

int main(int argc, string argv[])
{
    string c = get_string("C = ");
    //string arg = "JTREKYAVOGDXPSNCUIZLFBMWHQ";
    substitute(c, argv[1]);
    printf("\n");
}

void substitute(string x, string key)
{
    for (int i = 0, n = strlen(x); i < n; i++)
    {
        if (isupper(x[i]))
        {
            printf("%c", key[(int) x[i] - 65]);
        }
        else if (islower(x[i]))
        {
            printf("%c", tolower(key[(int) x[i] - 97]));
        }
        else
        {
            printf("%c", x[i]);
        }
    }
}
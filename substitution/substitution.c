#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

void substitute(string x, string key);

int main(int argc, string argv[])
{
    string c = get_string("plaintext: ");
    //string arg = "JTREKYAVOGDXPSNCUIZLFBMWHQ";
    printf("ciphertext: ");
    substitute(c, argv[1]);
    printf("\n");
    return 0;
}

void substitute(string x, string key)
{
    for (int i = 0, n = strlen(x); i < n; i++)
    {
        if (isupper(x[i]))
        {
            printf("%c", toupper(key[(int) x[i] - 65]));
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
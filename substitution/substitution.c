#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

void substitute (string x, string key);
bool iscorrect (string x, int num);

int main(int argc, string argv[])
{
    if(iscorrect (argv[1], argc))
    {
        return 1;
    }
    else
    {
        string c = get_string("plaintext: ");
        //string arg = "JTREKYAVOGDXPSNCUIZLFBMWHQ";
        printf("ciphertext: ");
        substitute(c, argv[1]);
        printf("\n");
        return 0;
    }
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

bool iscorrect (string x)
{
    if (num != 1)
    {
        printf("Too much or not enough arguments");
        return 1;
    }
    if(strlen(x) != 26)
    {
        printf("Less than 26 letters! \n");
        return 1;
    }
    else
    {
        for (int i = 0, n = strlen(x); i < n; i++)
        {
            if (isalpha(x[i]))
            {
                continue;
            }
            else
            {
                printf("Not all from the alphabet! \n");
                return 1;
            }
        }
        for (int i = 0, n = strlen(x); i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (toupper(x[i]) == toupper(x[j]) && i != j)
                {
                    printf("A double has been detected! \n");
                    return 1;
                }
            }
        }
        return 0;
    }
}

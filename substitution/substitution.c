#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

void substitute (string x, string key);
bool iscorrect (string x);

int main(int argc, string argv[])
{
    if(iscorrect (argv[1]))
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
    if(strlen(x) != 26)
    {
        printf("Less than 26 letters! \n");
        return 1;
    }
    else
    {
        for (int i = 0, n = strlen(x); i < n; i++)
        {
            if (((int) x[i] >= 65 && (int) x[i] <= 90) ^ ((int) x[i] >= 97 && (int) x[i] <= 121))
            {
                return 0;
            }
            else
            {
                printf("Not all from the alphabet!");
                return 1;
            }
        }
        return 0;
    }
}

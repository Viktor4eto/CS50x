#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

void substitute(string x, string key);
bool iscorrect(string x);

int main(int argc, string argv[])
{
    // Are the arguments the right ammount
    if (argc != 2)
    {
        printf("Too much or not enough arguments! \n");
        return 1;
    }
    // Is the key correct
    else if (iscorrect(argv[1]))
    {
        return 1;
    }
    else
    {
        string c = get_string("plaintext: ");
        //string arg = "JTREKYAVOGDXPSNCUIZLFBMWHQ";
        //Prints the "ciphertext: " + the substituted message + a new line
        printf("ciphertext: ");
        substitute(c, argv[1]);
        printf("\n");
        return 0;
    }
}
//Substite all chars into the array
void substitute(string x, string key)
{
    for (int i = 0, n = strlen(x); i < n; i++)
    {
        //If the char is an upper case
        if (isupper(x[i]))
        {
            printf("%c", toupper(key[(int) x[i] - 65]));
        }
        //If the char is a lower case
        else if (islower(x[i]))
        {
            printf("%c", tolower(key[(int) x[i] - 97]));
        }
        //If the char is not a letter
        else
        {
            printf("%c", x[i]);
        }
    }
}

bool iscorrect(string x)
{
    //Is the key the correct lenght
    if (strlen(x) != 26)
    {
        printf("Less than 26 letters! \n");
        return 1;
    }
    else
    {
        //Are all chars from the alphabet
        for (int i = 0, n = strlen(x); i < n; i++)
        {
            if (isalpha(x[i]))
            {
                //If yes, continue to the next loop
                continue;
            }
            else
            {
                printf("Not all from the alphabet! \n");
                return 1;
            }
        }
        //Are all the chars unique (both upper and lower)
        for (int i = 0, n = strlen(x); i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                //If the upper x[i] and x[j] are the same and i and j are different, there is a double in the key
                if (toupper(x[i]) == toupper(x[j]) && i != j)
                {
                    printf("A double has been detected! \n");
                    return 1;
                }
            }
        }
        //If we dont exit beforehand, everything is correct
        return 0;
    }
}

#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

string substitute(string x, string key);

int main(void)
{
    string c = get_string("C = ");
    string arg = "JTREKYAVOGDXPSNCUIZLFBMWHQ";
    printf("%s \n", substitute(c, arg));
}

string substitute(string x, string key)
{
    string new = "";
    for (int i = 0, n = strlen(x); i < n; i++)
    {
        if (isupper(x[i]))
        {
            new[i] = key[i] - 65;
        }
        else if (islower(x[i]))
        {
            new[i] = key[i] - 141;
        }
    }
    return new;
}
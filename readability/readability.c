#include <cs50.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

int count_letters(string text);

int main(void)
{
    string text = get_string("Text: ");
    printf("%i \n", count_letters(text));
}

int count_letters(string text)
{
    int count = 0;
    for(int i = 0, n = strlen(text); i < n; i++)
    {
        if(islower(text[i]) ^ isupper(text[i]))
        {
            count++;
        }
    }
    return count;
}
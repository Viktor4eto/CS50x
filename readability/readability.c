#include <cs50.h>
#include <string.h>
#include <stdio.h>

int count_letters(string text);

int main(void)
{
    string text = get_string("Text: ");
    printf("%i", count_letters(text));
}

int count_letters(string text)
{
    int count;
    for(int i = 0; n = strlen(text); i < n; i++)
    {
        if(islower(text[i]) ^ isupper(text[i]))
        {
            count++;
        }
    }
    return count;
}
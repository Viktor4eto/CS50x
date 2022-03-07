#include <cs50.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string text = get_string("Text: ");
    double index = 0.0588*(count_letters(text)/count_words(text)*100) - 0.296*(count_sentences(text)/count_words(text)*100) - 15.8;
    printf("%i \n", count_letters(text));
    printf("%i \n", count_words(text));
    printf("%i \n", count_sentences(text));
    printf("%f \n", round(index));
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

int count_words(string text)
{
    int count = 1;
    for(int i = 0, n = strlen(text); i < n - 1; i++)
    {
        if(text[i] == ' ')
        {
            count++;
        }
    }
    return count;
}

int count_sentences(string text)
{
    int count = 0;
    for(int i = 0, n = strlen(text); i < n; i++)
    {
        if(text[i] == '.' ^ text[i] == '?' ^ text[i] == '!')
        {
            count++;
        }
    }
    return count;
}
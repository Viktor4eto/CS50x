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
    float letters = count_letters(text);
    float words = count_words(text);
    float sentences = count_sentences(text);
    float L = letters/words;
    float S = sentences/words;
    float index = 0.0588*L*100 - 0.296*S*100 - 15.8;
    if (index < 1)
    {
        printf("Before Grade 1 \n");
    }
    else if (index > 16)
    {
        printf("Grade 16+ \n");
    }
    else
    {
        printf("Grade %i \n", (int) round(index));
    }

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
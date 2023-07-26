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
    //Gets text
    string text = get_string("Text: ");
    //Variables for easier understanding of the code
    float letters = count_letters(text);
    float words = count_words(text);
    float sentences = count_sentences(text);
    printf("%f %f %f \n", letters, words, sentences);
    float L = letters / words;
    float S = sentences / words;
    //Formula
    float index = 0.0588 * L * 100 - 0.296 * S * 100 - 15.8;
    printf("%f \n", index);
    //Grade logic
    if (index < 1)
    {
        //Before Grade 1
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        //Grade 16+
        printf("Grade 16+\n");
    }
    else
    {
        //Grade X
        printf("Grade %i\n", (int) round(index));
    }

}
//Counts letters
int count_letters(string text)
{
    int count = 0;
    //Loop for counting
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        //Check for letters
        if (islower(text[i]) ^ isupper(text[i]))
        {
            count++;
        }
    }
    return count;
}
// Counts words
int count_words(string text)
{
    int count = 1;
    //Loop
    for (int i = 0, n = strlen(text); i < n - 1; i++)
    {
        //Checks for spaces
        if (text[i] == ' ')
        {
            count++;
        }
    }
    return count;
}
//Counts sentences
int count_sentences(string text)
{
    int count = 0;
    //Loop
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        //Checks for punctuation
        if (text[i] == '.' ^ text[i] == '?' ^ text[i] == '!')
        {
            count++;
        }
    }
    return count;
}
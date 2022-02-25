#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //Asks for your name
    string name = get_string("What's your name? ");
    //Prints "Your name is" followed by your name
    printf("Your name is %s. \n", name);
}
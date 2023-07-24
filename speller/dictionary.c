// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <strings.h>
#include <stdlib.h>
#include <string.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 256;
int words = 0;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    int hashed = hash(word);

    for (node *ptr = table[hashed]; ptr != NULL; ptr = ptr->next)
    {
        if(strcasecmp(ptr -> word, word) == 0){
            return true;
        }
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    //return toupper(word[0]) - 'A';
    /*int hashed = 0;
    for(int i = 0; i < sizeof(word); i++){
        hashed += toupper(word[i]);
    }*/

    long long hashed = 0;
    for(int i = 0; word[i] != '\0'; i++)
    {
        hashed = 31*hashed + tolower(word[i]);
    }
    //printf("%i, \n", hashed);
    return hashed % 255;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    FILE *file = fopen(dictionary, "r");
    char s[LENGTH + 1];
    int hashed;

    if(file == NULL)
    {
        return false;
    }

    node *tmp;


    while(fscanf(file, "%s", s) != EOF)
    {
        hashed = hash(s);

        tmp = malloc(sizeof(node));

        if(tmp == NULL)
        {
            return false;
        }

        strcpy(tmp -> word, s);

        if(table[hashed] == NULL)
            tmp -> next = NULL;
        else
            tmp -> next = table[hashed];

        table[hashed] = tmp;
        words++;
    }

    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return words;
}

void freeList(node *current){
    if(current -> next != NULL){
        freeList(current -> next);
    }

    free(current);

}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for(int i = 0; i < N; i++){
        if(table[i] != NULL)
            freeList(table[i]);
    }

    return true;
}


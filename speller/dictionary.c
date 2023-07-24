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
const unsigned int N = 26;
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
    int hashed = toupper(word[0]) - 'A';



    words++;
    return hashed;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    FILE *file = fopen(dictionary, "r");
    char *word;
    int hashed;

    if(file == NULL)
    {
        return false;
    }

    node *tmp;


    while(fscanf(file, %s, word) != EOF)
    {
        hashed = hash(word);

        tmp = malloc(sizeof(node));

        if(tmp == NULL)
        {
            return false;
        }

        strcpy(tmp -> word, word);
        tmp -> next = table[hashed];
        table[hashed] = tmp;

    }

    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return words;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for(int i = 0; i < N; i++){
        freeList(table[i]);
    }

    return true;
}

void freeList(node* current){
    if(current -> next == NULL){
        free(current);
    }

    else{
        freeList(current -> next);
        free(current);
    }
}

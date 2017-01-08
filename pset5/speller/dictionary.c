/**
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "dictionary.h"

#define arraySize 27

typedef struct myStruct{
    bool myBool;
    struct myStruct* next[arraySize];
} node;

// Declarations
void unallocateMem(node* myPointer);
node* first;
unsigned int dictionarySize = 0;



/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char *word)
{
    // Check if the first node has been is initialized 
    //Check if the dictionary is loaded
    if (first == NULL)
    {
        printf("Error checking word '%s', because the dictionary has not being loaded or the first node has not initialized yet.",word);
        return false;
    }
    
    node* current = first;
    int n = strlen(word);
    
    for(int i = 0; i < n; i++)
    {
        // Change element in array index to lower case
        int c = tolower(word[i]);
        
        if (c == '\'')
            c = 26;
        else
            c = c - 'a';
            
        // if the index if its pointing to a null return false 
        if (current -> next[c] == NULL)
            return false;
        // else traverse through the nodes one by one
        else
            current = current -> next[c];
    }
    
    // Return true if current points to the end of a word
    if(current -> myBool)
        return true;
    else
        return false;

    return false;
}

/**
 * Loads dictionary into memory. Returns true if successful else false.
 */
bool load(const char *dictionary)
{
    // Allocate the first node using malloc
    first = malloc(sizeof(node));
    
    // Open the dictionary ile
    FILE* f1 = fopen(dictionary, "r");
    if (f1 == NULL)
    {
        printf("Couldn't open %s.\n", dictionary);
        return false;
    }
    
    // track the current position via a pointer
    node* current = first;
    
    // Loop through the dictionary, reading character by character
    for (int c = fgetc(f1); c != EOF; c = fgetc(f1))
    {
        // Check for alphabet or apostrophe
        if (isalpha(c) || (c == '\''))
        {
            if (c == '\'')
                c = 26;
            else 
                c = c-'a';
            
            // Allocate memory for the next node if not allocated already
            if(current -> next[c] == NULL)
            {
                current -> next[c] = malloc(sizeof(node));
            }
            
            // Move on to the next node
            current = current -> next[c];
        }
        
        else if (c == '\n')
        {
            current -> myBool = true;
            // Reset the pointer for a new word
            current = first;
            dictionarySize++;
        }
        
    }
    fclose(f1);
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    return dictionarySize;
    //return 0;
}

/**
 * Unloads dictionary from memory. Returns true if successful else false.
 */
bool unload(void)
{
    unallocateMem(first);
    return true;
}

void unallocateMem(node* myPointer)
{
    for (int i = 0; i < arraySize; i++)
    {
        if (myPointer -> next[i] != NULL)
        {
            unallocateMem(myPointer -> next[i]);
        }
    }
    free(myPointer);
    
}

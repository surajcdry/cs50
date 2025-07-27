// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

int word_counter = 0;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    // Hash word to obtain a hash value
    int hash_value = hash(word);

    // Access linked list at that index in the hash table
    node *cursor = table[hash_value];

    while (cursor != NULL)
    {
        // Traverse linked list, looking for the word (strcasecmp)
        if (strcasecmp(cursor->word, word) == 0)
        {
            return true; // found
        }
        else
        {
            cursor = cursor->next;
        }
    }

    return false; // couldn't find
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    for (int i = 0; i < N; i++)
    {
        table[i] = NULL;
    }

    // Open dictionary file
    FILE *dict_file = fopen(dictionary, "r");
    if (dict_file == NULL)
    {
        printf("Error while opening dict_file\n");
        return false;
    }

    // Read strings from file (dictionary) one at a time
    char buffer[LENGTH];

    while (fscanf(dict_file, "%s", buffer) != EOF)
    {
        // Create a new node for each word
        node *new_word = malloc(sizeof(node));

        // Hash word to obtain a hash value
        int hash_value = hash(buffer);

        // Insert node into hash table at that location
        strcpy(new_word->word, buffer);
        new_word->next = table[hash_value];
        table[hash_value] = new_word;
        word_counter++;
    }

    fclose(dict_file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return word_counter;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i++)
    {
        node *tmp = table[i];
        node *cursor = table[i];

        while (cursor != NULL)
        {
            cursor = cursor->next;
            free(tmp);
            tmp = cursor;
        }
    }

    return true;
}

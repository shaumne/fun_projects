// Implements dictionary's
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

#define HASHTABLE_SIZE 10000

// Defines struct for a node
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

node *hashtable[HASHTABLE_SIZE];

// This function takes a word as input (in the form of a string)
// It uses a hash function to generate an index for the word in the hash table
// The index is then returned for use in inserting the word into the linked list at the
unsigned int hash_index(const char *hash_this)
{
    unsigned int hash = 0;
    for (int i = 0, n = strlen(hash_this); i < n; i++)
    {
        hash = (hash << 2) ^ hash_this[i];
    }
    return hash % HASHTABLE_SIZE;
}

int word_count = 0;

bool load(const char *dictionary)
{
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }

    // Initialize hashtable to NULL
    for (int i = 0; i < HASHTABLE_SIZE; i++)
    {
        hashtable[i] = NULL;
    }

    // Reads dictionary word by word (populating hash table with nodes containing words found in dictionary)
    char word[LENGTH + 1];
    while (fscanf(file, "%s", word) != EOF)
    {
        // Mallocs a node for each new word (i.e., creates node pointers)
        node *new_node = malloc(sizeof(node));

        // Checks if malloc succeeded, returns false if not
        if (new_node == NULL)
        {
            unload();
            fclose(file);
            return false;
        }

        // Copies word into node if malloc succeeds
        strncpy(new_node->word, word, sizeof(new_node->word) - 1);
        new_node->word[sizeof(new_node->word) - 1] = '\0';

        // Initializes & calculates index of word for insertion into hashtable
        int h = hash_index(new_node->word);

        // Inserts new nodes at beginning of lists
        if (hashtable[h] == NULL)
        {
            new_node->next = NULL;
            hashtable[h] = new_node;
        }
        else
        {
            new_node->next = hashtable[h];
            hashtable[h] = new_node;
        }
        word_count++;
    }

    fclose(file);
    return true;
}

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // Convert word to lowercase and make a copy of it
    char word_copy[LENGTH + 1];
    for (int i = 0; i < strlen(word); i++)
    {
        word_copy[i] = tolower(word[i]);
    }
    word_copy[strlen(word)] = '\0';

    // Hash the word to get the bucket index
    int bucket_index = hash_index(word_copy);

    // Check if the word is in the dictionary
    for (node *cursor = hashtable[bucket_index]; cursor != NULL; cursor = cursor->next)
    {
        if (strcasecmp(cursor->word, word_copy) == 0)
        {
            return true;
        }
    }
    return false;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return word_count;
}

bool unload(void)
{
    // Iterate over each bucket in the hashtable
    for (int i = 0; i < HASHTABLE_SIZE; i++)
    {
        // Set the head of the linked list for the bucket to a new variable
        node *head = hashtable[i];

        // Iterate over each node in the linked list for the bucket
        while (head != NULL)
        {
            // Store the next node in a separate variable
            node *next = head->next;

            // Free the memory allocated for the current node
            free(head);

            // Set the head to the next node
            head = next;
        }

        // After all nodes in the linked list have been freed, set the hashtable bucket to NULL
        hashtable[i] = NULL;
    }

    return true;
}
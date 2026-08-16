// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h> // Declares strcasecmp()

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 1899;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    int value = hash(word);
    if (value == N + 1)
    {
        return false;
    }

    for (node *ptr = table[value]; ptr != NULL; ptr = ptr->next)
    {
        if ((strcasecmp(word, ptr->word)) == 0)
        {
            return true;
        }
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{

    int length = strlen(word);
    if (length == 1)
    {
        return tolower(word[0]) - 'a';
    }
    else
    {
        if (word[1] == '\'')
        {
            return ((length-1) * 26) + 1 + ((tolower(word[0]) - 'a')) ;
        }
        return ((length-1) * 26) + 1 + ((tolower(word[0]) - 'a') ) +
                   ((tolower(word[1]) - 'a') + 1);
    }
    return N + 1; // no value
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    for (int i = 0; i < N; i++)
    {
        table[i] = NULL;
    }
    // opening the dictionary file
    FILE *source = fopen(dictionary, "r");
    if (source == NULL)
    {
        return false;
    }
    char words[LENGTH + 1];
    int index = 0;
    int value = 0;
    char s;
    while ((fread(&s, sizeof(char), 1, source)) == 1)
    {
        if (s == '\n')
        {
            if (index != 0)
            {
                words[index] = '\0';

                value = hash(words);

                if (value == N + 1)
                {
                    return false;
                }

                node *n = malloc(sizeof(node));
                if (n == NULL)
                {
                    unload();
                    fclose(source);
                    return false;
                }
                for (int i = 0; i < index + 1; i++)
                {
                    n->word[i] = words[i];
                }
                if (table[value] == NULL)
                {
                    table[value] = n;
                    n->next = NULL;
                }
                else
                {
                    n->next = table[value];
                    table[value] = n;
                }

                index = 0;
            }
        }
        else if (isalpha(s))
        {
            words[index] = s;
            index += 1;
        }
        else if (s == '\'' && index > 0)
        {
            words[index] = s;
            index += 1;
        }
    }
    fclose(source);
    return true;
}
// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        for (node *ptr = table[i]; ptr != NULL; ptr = ptr->next)
        {
            count++;
        }
    }
    return count;
}
// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        node *tmp = NULL;
        node *ptr = table[i];
        while (ptr != NULL)
        {
            tmp = ptr->next;
            free(ptr);
            ptr = tmp;
        }
    }
    return true;
}


#include <stdio.h>
#include <stdlib.h>

#include <ctype.h>
#include <stdbool.h>
#include <string.h>

#include "dictionary.h"

#define HASHTABLE_SIZE 10000

// create word counter for size
int wordCount = 0;

// linked link struct
typedef struct node
{
    // word's length + NULL character
    char word[LENGTH + 1];
    struct node* next;
}
node;

// Hashtable array
node* hashtable[HASHTABLE_SIZE];

 
// source: http://stackoverflow.com/questions/20462826/hash-function-for-strings-in-c
int hash (char* key)
{
    int hash = 0;
    int n;
    for (int i = 0; key[i] != '\0'; i++)
    {
        // alphabet case
        if(isalpha(key[i]))
            n = key[i] - 'a' + 1;

        // comma case
        else
            n = 27;

        hash = ((hash << 3) + n) % HASHTABLE_SIZE;
    }
    return hash;
}

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    // create variable to hold word
    char temp[LENGTH + 1];
    
    // convert every character in word to lowercase
    for (int i = 0, n = strlen(word); i < n; i++)
    { 
        if (isalpha(word[i]))
        {
            temp[i] = tolower(word[i]); 
        }  
        
        else 
        
        {
            temp[i] = word[i];
        }  
    }
    
    temp[strlen(word)] = '\0'; // source: cs50 stackexchange
    
    // get hashed word's index
    int hash_index = hash(temp);

    // find head of that index
    node* head = hashtable[hash_index];
     
    // traverse through linked list 
    for (node* cur = head; cur != NULL; cur = cur->next)
    {
        // find if linnked list contains word
        if (strcmp(cur->word, temp) == 0)
        {
            return true;
        }   
    }  
     
    return false;
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    // // open file
    FILE* file = fopen(dictionary, "r");
    
    // check if file exists
    if (file == NULL)
    {
        return false;
    }
    
    // word length plus NULL character
    char word[LENGTH + 1];
    
    // loop until end of file
    while (feof(file) == 0) 
    {
        // scan every line of the dictionary for word
        fscanf(file, "%s\n", word);
        
        node* new_node = malloc(sizeof(node));
        
        if (new_node == NULL)
        {
            unload();
            return false;
        }
        
        if (new_node != NULL)
        {
            strcpy(new_node->word, word);  // Source: cs50 reddit
            new_node->next = NULL;
        }
       
        wordCount++;
        
        int hash_index = hash(new_node->word);
        
        // insert node at head
        new_node->next = hashtable[hash_index];
        hashtable[hash_index] = new_node; 
            
    }
    
    fclose(file);
    
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    
    return wordCount;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{   
    // go through all of the indexes in the hashtable 
    for (int i = 0; i < HASHTABLE_SIZE; i++)
    {
        node* head = hashtable[i];
        
        while (head != NULL)
        {
            node* ptr = head->next;
            
            free(head);
            head = ptr;
        }   
    }   
    return true;
}

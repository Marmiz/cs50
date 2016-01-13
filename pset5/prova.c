/****************************************************************************
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 ***************************************************************************/
#include <cs50.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "dictionary.h"

#define SIZE 100000

//initialize counter for number of word counted
int wordcount = 0;

//define a hush function that sort by the fist letter of the word
int hash(char* key)
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

        hash = ((hash << 3) + n) % SIZE;
    }
    return hash;

}

//define linked list
typedef struct node
{
    char* word[LENGTH+1];
    struct node* next;   
}
node;

//Hashtable array
node* hashtable[SIZE];

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    //create temporary storae for the variable
    char temp[LENGTH+1];
    
    //convert every charachter in lower-case
    for (int i = 0, n=strlen(word); i < n; i++)
    {
        if (isalpha(word[i]))
        {
            temp[i]=tolower(word[i]);
        }
        
        else
        {
            temp[i]= word[i];
        }
    }
    
    temp[strlen(word)] = '\0';
    
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
    // open the dictionary
    FILE* file=fopen(dictionary,"r");
    
    if (file==NULL)
    { 
    return false;
    }
    
    char word[LENGTH+1];
    
    //iterate the scan till the end of file
    while(feof(file) == 0)
    {
        fscanf(file, "%s\n", word);
       
       //create new node 
       node* new = malloc(sizeof(node));
        
        //sanity check
        if (new == NULL)
        {
            unload();
            return false;
        }
        
        if (new != NULL)
       {
           //initialize new node
           new -> word = word;
           new -> next = NULL;
       
           //insert new node with the hash value at head        
           int hash_index = hash (new -> word);       
           new -> next = hashtable[hash_index];
           hashtable[hash_index] = new;
       
           wordcount++;
       }
    }
    
    fclose (file);
    
    return true;
    
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    if (wordcount != 0)
    {
        return wordcount;
    }
    
    else
    {
        return 0;
    }
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    
    //go trough all the hash index
    for (int i=0; i < SIZE; i++)
    {
        //Create a new cursor at head that free all the others node in the linked list
        node* cursor = hashtable[i];
        
        while (cursor != NULL)
        {
            node* temp = cursor;
            cursor = cursor -> next;
            free (temp);
        }
        
        return true;
    }
    
    return false;
}

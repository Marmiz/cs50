#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>



void cipher(int key, int text);

int main(int argc, char* argv[])
{
    // error checking
    if (argc != 2)
    {
        printf("don't forget to insert the key!\n");
        return 1;
    }
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (isalpha(argv[1][i]) == 0)
        {
            printf("Non-alpha char in key!\n");
            return 1;
        }
    }
    
    
    // store key and key length
    char* key = argv[1];
    int keylen = strlen(key);
    
    // get message string
    char* text = GetString();
    
    // declare key counter
    int j = 0;
    
    // encript the string
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        // checks if letter is an alpha
        if (isalpha(text[i]))
        {
            // check the case of the key
            if (isupper(key[j % keylen]))
            {
                int k = key[j % keylen] - 65;
                cipher(k, text[i]);
            }
            else
            {
                int k = key[j % keylen] - 97;
                cipher(k, text[i]);
            }
            
            // iterate the key counter 
            j++;
        }
        
        // print non-alpha char without iterating key
        else
            printf("%c", text[i]);
    }
    // return to the next line
    printf("\n");
}

void cipher(int key, int text)
{
    // check if text is uppercase
    if (isupper(text))
    {
        // encrypt using upper
        int result = (text - 65 + key) % 26 + 65;
        printf("%c", result);
    }
    else
    {
        // encrypt using lower
        int result = (text - 97 + key) % 26 + 97;
        printf("%c", result);
    }
}

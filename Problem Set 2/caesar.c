/**
*Claudio Restifo
*pset 2 - Caesar is a program who encript a string using a key given by the user.
**/

#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    //check that the user digit two commands in the command line
    if ( argc != 2)
    {
        printf("You forgot to give me a key, please lunch again the program and digit a key.");
        return 1;
    }
    
    //convert the array in a int
    int k = atoi(argv[1]);
    
    // check that the key is valid
    if (k < 1)
    {
    printf("Invalid key, please give me a positive number.");
    return 1;
    }
    
    //get the plain text from the user
    string text = GetString();
    
    //loop to print the cyphertext
    for (int i = 0, n = strlen (text); i < n; i++)
    {
     
     //convert only text letters
     if (isalpha (text[i]))
     {
         //formula for the uppercases letters
         if (isupper (text[i]))
         {
             int result = ((text[i] + k - 65) %26+ 65);
             printf("%c", result);   
         }
         
         //formula for the lowercase letters
         if (islower (text[i]))
         {
             int result = ((text[i] + k - 97) %26 + 97);
             printf("%c", result);
         }
         
     }
         //for the symbols
         else
         {
         printf("%c", text[i]);
         }
     
        
    }
    
    printf("\n");  
   

}

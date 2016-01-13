/**
*Claudio Restifo
*pset2 - writing a probram that print the initials of a name in caps
*/ 

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    //get name
    string name = GetString();
    
    //check error
    if (name != NULL)
    
    {
        //print first initial
        printf("%c", toupper(name[0]));
        
        
        //print any other initial
        for (int i = 0, n = strlen(name); i <= n; i++)
        {
            if (name[i] == ' ')
            {
                printf("%c", toupper(name[i+1]));
            }
        }
        
        //print a new line
        printf("\n");
    }
}

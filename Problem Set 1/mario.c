#include <cs50.h>
#include <stdio.h>
int main(void)
{
    int height;
    
    do
    {
    printf ("Enter the heigt of your piramid: ");
    height = GetInt();
    }
    while ( (height<0) || (height>23) );
  
    for (int i = 1; i <= height; i++)
    {
        for (int spaces = height - i; spaces >0; spaces--)
        {
            printf(" ");
        }
        
        for (int lenght = 0; lenght <= i; lenght ++)
        {
            printf("#");
        }
        
    printf("\n");
       
    }
   
}

#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main (void)
{

    // set the start value of change = 0 //
    float change_input;
    int coin_count = 0;
    
    printf("How much change do I owe you? \n");
    
    //set the limit to only positive numbers//
    do
    {
        change_input = GetFloat(); 
            if (change_input <= 0)
            {                     
                printf(" Try again! your change cannot be a negative number!\n");
            }
    }
   
    //start the loop// 
    while (change_input <= 0);
    
    //round it to cents//
    int change_cents = roundf((change_input*100));
    
    //adding cents//
    while (change_cents >= 25)
    {
         change_cents -= 25;
         coin_count++;        
    }
    
    while (change_cents >= 10)
    {
        change_cents -= 10;
        coin_count++;
    }
    
    while (change_cents >= 5)
    {
        change_cents -= 5;
        coin_count++;
    }
    
    while (change_cents >= 1)
    {
        change_cents -= 1;
        coin_count++;
    }
    
    printf("%d\n", coin_count);
}

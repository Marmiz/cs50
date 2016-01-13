/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 * Claudio Restifo 
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <cs50.h>

int main(int argc, char* argv[])
{
    //open memory card. Hard coded for semplicity
    FILE* file = fopen ("card.raw", "r");
    
    //sanity checks
    if ( file == NULL)
    {
        fclose(file);
        printf ("Unable to open card.raw\n");
        return 1;
    }
    
    //define img
    typedef uint8_t BYTE;
    
    //define a buffer of 512 bytes
    BYTE buffer[512];
    
    //define  tomporary storage for the image
    FILE* temp = NULL;
    
    //set counters for restored pictures
    int counter = 0;
    
    //name the picture with a three digit number from 000 up
    char name[10];
    
    //Until end of file is reached
    while (!feof(file))
    {
        //check fist digit to verify it's a .jpg
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer [2] == 0xff && (buffer [3] == 0xe0 || buffer [3] == 0xe1))
        {
            //if already exist close the file
            if (temp != NULL)
            {
                fclose(temp);
            }
        
            //label the opened file with a three digit name
            sprintf(name, "%03d.jpg", counter);
            
            //next file in line
            temp= fopen(name,"w");
            
            //update counter
            counter++;
            
            //new file with buffer
            fwrite(buffer, sizeof(buffer), 1, temp);
        }
        
        //copy the jpg into a new temp image
        else if (counter > 0)
        {
            fwrite(buffer, sizeof(buffer),1, temp);
        }
        
        fread(buffer, sizeof(buffer), 1, file);
    }
    
    //close the file
    fclose(file);
    
    return 0;
}

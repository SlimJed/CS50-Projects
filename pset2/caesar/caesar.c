#include <stdio.h>
#include "cs50.h"
#include <string.h>
//#include <cstring>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    //Check if the arguments entered is not equal to 2
    if(argc != 2)
    {
        printf("Usage: ./caesar <key>\n");
        return 1;
    }
    //Converts the input to integer
    int k = atoi(argv[1]);
    if(k < 0)
    {
        printf("Key must be a non-negative integer.\n");
        // return error
        return 1;
    }
    
    printf("plaintext:");
    //Get string from user
    string p = GetString();
    
    //checks if the string entered is empty
    if(p[0] !='\0')
    {
        int n = 0;
        //Set equalls to the lenght of the string
        n = strlen(p);
        
        printf("ciphertext:");
        //iterates through every element of the string
        for(int i = 0; i < n; i++)
        {
            
            //checks if the element ie LowerCase
            if(islower(p[i]))
            {
                printf("%c", (p[i] - 97 + k) % 26 + 97);
            }
            
            //checks if the element ie UpperCase
            else if(isupper(p[i]))
            {
                printf("%c", (p[i] - 65 + k) % 26 + 65);
            }
            else
            {
                //do nothing
                printf("%c", p[i]);
            }
            
            
        }
        printf("\n");
        return 0;
    }
}
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    //Get name input fromu ser
    string name = GetString();
   
    // checks if the name is not empty
    if(name != NULL)
    {
        //iterates through every element of the array
        for(int i = 0, l = strlen(name); i < l; i++)
        {
            /* checks if the letter is the first element in
            the string, checks if the char is before an empty space 
            and uses the index after the space 
            */
            if(i == 0 || name[i - 1] == ' ')
            {
                //Convert the chosen elements to UPPERCASE
                printf("%c", toupper(name[i]));
            }
        }
        //Print new line
        printf("\n");
    }
}
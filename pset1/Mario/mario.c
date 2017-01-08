#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //initializes height
    int height;
    //ask for a new height as long as height is not between 0 and 23
    do
    {
        printf("height: ");
        height = get_int();
    }
    while(height < 0 || height > 23);
    
    //for loop to iterate through each row
    for(int i = 1; i <= height; i++)
    {
        // add spaces to row
        for(int spaces = height - i; spaces > 0; spaces--)
        {
            printf(" ");
        }
        
        //add # to row
        for(int hashes = 0; hashes <= i; hashes++)
        {
            printf("#");
        }
        printf("\n");
    }
}

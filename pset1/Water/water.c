#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //initilise minutes and bottes to integer
    int minutes, bottles;
    
    //display text
    printf("minutes: ");
    
    //get minutes from user
    minutes = get_int();
    
    //bottles = the minutes inputes * a default value o 12
    bottles = minutes * 12;
    
    //print out bottles
    printf("bottles: %i\n", bottles);
}

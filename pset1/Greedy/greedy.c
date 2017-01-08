#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    //Uses float as type of change
    float change;
    printf("O hai! ");
    
    /* 
    asks the user for the amount of change that is owned 
    as long as the change is les than 0 
    */
    do
    {
        printf("How much change is owed?\n");
        change = GetFloat();
    }
    while(change < 0);
    
    int cents = round(change * 100);
    int coins = 0;
    /*
    as long as cent is greater than 0 run the code
    to calculate the amount of coin
    */
    while(cents > 0)
    {
        if(cents >= 25)
        {
            cents -= 25;
            coins++;
        }
        else if(cents >= 10)
        {
            cents -= 10;
            coins++;
        }
        else if(cents >= 5)
        {
            cents -= 5;
            coins++;
        }
        else
        {
            cents--;
            coins++;
        }
    }
    printf("%i\n", coins);
}

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
 
int getK(int lettersCiphered, string k);
 
int main(int argc, string argv[])
{	
    // Stop if invalid num of arguments recieved
    if (argc != 2)
    {
        printf("Invalid\n");
        return 1;
    }
 
    // Get the caesar k value
    string k = argv[1];
 
    // Check if k only contains letters
    for (int i = 0, length = strlen(k); i < length; i++)
    {
        if (!isalpha(k[i]))
        {
            printf("Invalid\n");
            return 1;
        }
    }
 
    printf("plaintext:");
    // Get the text to cipher
    string s = GetString();
 
    // Used for finding corresponding k value (we don't want to count spaces)
    int lettersCiphered = 0;
    
    
    printf("ciphertext:");
    
    
    // Iterate through the text to cipher
    for (int i = 0, length = strlen(s); i < length; i++)
    {
        char c = s[i];
 
        // Changes char depending on if it is uppercase, lowercase, or not a letter
        // Note: 65 ASCII 'A', and 97 is ASCII 'a'
        if (isupper(c))
        {
            char newC = (((c - 65) + getK(lettersCiphered,k)) % 26) + 65;
            printf("%c", newC);
            lettersCiphered++;
        }
        else if(islower(c))
        {
            char newC = (((c - 97) + getK(lettersCiphered,k)) % 26) + 97;
            printf("%c", newC);
            lettersCiphered++;
        }
        else
        {
            printf("%c", c);
        }
    }
 
    printf("\n");
 
    return 0;
}
 
/**
* Method to get corresponding letter of k
*/
int getK(int lettersCiphered, string k)
{
    int length = strlen(k);
    return tolower(k[lettersCiphered % length]) - 97;
}
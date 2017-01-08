#include <stdio.h>
#include <cs50.h>
#include <stdint.h>
 
typedef uint8_t BYTE; 
typedef struct
{
    BYTE zero;
    BYTE one;
    BYTE two;
    BYTE three;
}
SIGNATURE;

int main(void)
{
    // open the card file
    FILE *card = fopen("card.raw", "r");
    if(card == NULL)
    {
        fclose(card);
        fprintf(stderr, "Could not read from card file\n");
        return 1;
    }

    // file signature of the section of 512 bytes
    SIGNATURE signatureSegment;

    // the current jpg file to write jpg data on
    FILE* recoveredFile;
    
    char buffer[508];
    int jpgCount = 0;

    // tells if we've started collecting jpgs
    bool foundJpg = false;

    // do for each section of bytes (buffer)
    while(fread(&signatureSegment, sizeof(SIGNATURE), 1, card) > 0)
    {
        char* jpgName = malloc(sizeof(char) * 8);

        // read the rest of the section of 512 bytes into the buffer
        fread(&buffer, 508, 1, card);

        // check for the start of jpg
        if(signatureSegment.zero == 0xff && signatureSegment.one == 0xd8 &&
            signatureSegment.two == 0xff && (signatureSegment.three == 0xe0 ||
            signatureSegment.three == 0xe1))
        {
            foundJpg = true;
            
            // close the file, if writing to one previously
            if(jpgCount != 0)
                fclose(recoveredFile);

            // try to open a jpg file named ###.jpg
            sprintf(jpgName, "%03d.jpg", jpgCount++);
            recoveredFile = fopen(jpgName, "w");
            if(recoveredFile == NULL)
            {
                fclose(recoveredFile);
                fprintf(stderr, "Could not write %s.jpg\n", jpgName);
                return 2;
            }

            // write the first 4 bytes
            fwrite(&signatureSegment, sizeof(SIGNATURE), 1, recoveredFile);
            // write the next 508 bytes of the section
            fwrite(&buffer, 508, 1, recoveredFile);
        }
        // if jpg found and at the end of the photos?
        else if(foundJpg && jpgCount <= 51)
        {
            // recreate name of the jpg file
            sprintf(jpgName, "%03d.jpg", jpgCount);

            if(recoveredFile == NULL)
            {
                fclose(recoveredFile);
                fprintf(stderr, "Could not write %s\n", jpgName);
                return 3;
            }
            
            // write all 512 bytes to the file under jpgName
            fwrite(&signatureSegment, sizeof(SIGNATURE), 1, recoveredFile);
            fwrite(&buffer, 508, 1, recoveredFile);
        }

        // free mem for jpgName string
        free(jpgName);
    }
    // ensure the last jpg is closed
    fclose(recoveredFile);

    // close the mem card file
    fclose(card);
}

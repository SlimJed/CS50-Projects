/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */
 
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
 
bool binary_search(int value, int values[], int n);

bool search(int value, int values[], int n)
{
    // TODO: implement a searching algorithm
    if (n < 1 || value < 1)
    {
        return true;
    }
    else
    {
        return binary_search(value,values,n);
    }
}

bool binary_search(int value, int values[], int n)
{
    int high = n-1;
    int low = 0;
    
    while (n > 0)
    {
        int mid = (high - low) / 2 + low;
        if (values[mid] == value)
        {
            return true;
        }
        else if (values[mid] > value)
        {
            high = mid - 1;
        }
        else if (values[mid] < value)
        {
            low = mid + 1;
        }
        n = high - low + 1;
    }
    return false;
}


/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement an O(n^2) sorting algorithm
    // using a temporary variable for swapping
    int temp, i, j;
    
    // TODO: implementing bubble sort
    for(i = 0; i < (n - 1); i++)
    {
        for(j = 0; j < (n - i - 1);j++)
        {
            if (values[j] > values[j+1])
            {
                temp = values[j];
                values[j] = values[j+1];
                values[j+1] = temp;
            }
        }
    }
}
#include <stdbool.h>

void InsertionSort(int* array, int size)
{
    int i,j;
    int computing;
    
    for(i = 1; i < size; i++)
    {
        computing = array[i];
        for (j = i; j > 0 && array[j - 1] > computing; j--) 
        //Invert sign '>'' to invert order
        {
            array[j] = array[j - 1];
        }
        array[j] = computing;

    }
}

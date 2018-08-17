#include <stdbool.h>
#include <stdlib.h>     /* srand, rand */

static void swap_up(int* a, int* b)
{
    int swap = 0;
    
    if(*a > *b)
    {
        swap = *a;
        *a = *b;
        *b = swap;
    }
}

static void swap_down(int* a, int* b)
{
    int swap = 0;
    
    if(*a < *b)
    {
        swap = *a;
        *a = *b;
        *b = swap;
    }
}

void bubbleSort(int* array, int size, bool inverted)
{
    int i,j;
    int swap = 0;
    
    void (*sort)(int* a, int* b) = &swap_up;
    
    if(inverted)
    {
        sort = &swap_down;
    }
    
    for(i = 0; i < size; i++)
    {
        for(j = 0; j < size - i - 1; j++)
        {
            sort(&array[j], &array[j+1]);
        }
    }
}

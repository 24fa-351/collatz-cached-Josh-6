#ifndef map
#define map
#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include "collatz_calc.h"

int MAX_SIZE;

int size = 0; // Current number of elements in the map

typedef int64_t (*Functionpointer)(int64_t);
Functionpointer fib_provider = NULL;

int64_t *memo_num = NULL;
int64_t *memo_steps = NULL;

int getIndex(int key)
{
    for (int i = 0; i < size; i++)
    {
        if (memo_num[i] == key)
        {
            return i;
        }
    }
    return -1; // Key not found
}

// Function to insert a key-value pair into the map
void insert(int key, int value)
{
    int index = getIndex(key);
    if (index == -1)
    { // Key not found
        memo_num[size] = key;
        memo_steps[size] = value;
        size++;
    }
    else
    { // Key found
        memo_steps[index] = value;
    }
}

// Function to get the value of a key in the map
int get(int key)
{
    int index = getIndex(key);
    if (index == -1)
    { // Key not found
        return -1;
    }
    else
    { // Key found
        return memo_steps[index];
    }
}

// Function to print the map
void printMap()
{
    for (int i = 0; i < size; i++)
    {
        printf("%ld: %ld\n", memo_num[i], memo_steps[i]);
    }
}


int steps = 0;
int hits = 0;
int miss = 0;
int64_t memo(int64_t num)
{
    if (memo_num == NULL)
    {
        memo_num = (int64_t *)malloc((MAX_SIZE) * sizeof(int64_t));
        memo_steps = (int64_t *)malloc((MAX_SIZE) * sizeof(int64_t));

        for (int i = 0; i < MAX_SIZE; i++)
        {
            memo_num[i] = -1;
        }
    }
    int code = 1;
    while(num != 1)
    {
        num = collatz(num);
        steps++;
    }
    if (memo_num[size] == -1)
    {
        memo_num[size] = collatz(num);
        // printf("Adding to cache: %d\n", user_num);
    }
    /*else
     {
         printf("Recieving from cache: %d\n", user_num);
     }
     */
    return memo_num[num];
}

int memoize(int N, int max, int min, char *policy[], int cache_size)
{
    MAX_SIZE = cache_size;
    int step;
    fib_provider = memo;
    for (int i = 0; i < N; i++)
    {
        int random_num = rand() % (max - min + 1) + min;
        steps = memo(random_num);
    }

    return step;
}
#endif // map
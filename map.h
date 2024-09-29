#ifndef map
#define map
#include <stdio.h> 
#include <string.h>
#include <inttypes.h> 
#include "collatz_calc.h"

#define MAX_SIZE 1000 // Maximum number of elements in the map 
  
int size = 0; // Current number of elements in the map 

typedef int64_t (*Functionpointer)(int);
Functionpointer fib_provider = NULL;

int64_t *memo_num = NULL;
int64_t *memo_steps = NULL;

int getIndex(int key) 
{ 
    for (int i = 0; i < size; i++) { 
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
    if (index == -1) { // Key not found 
        memo_num[size] = key; 
        memo_steps[size] = value; 
        size++; 
    } 
    else { // Key found 
        memo_steps[index] = value; 
    } 
} 
  
// Function to get the value of a key in the map 
int get(int key) 
{ 
    int index = getIndex(key); 
    if (index == -1) { // Key not found 
        return -1; 
    } 
    else { // Key found 
        return memo_steps[index]; 
    } 
} 
  
// Function to print the map 
void printMap() 
{ 
    for (int i = 0; i < size; i++) { 
        printf("%ld: %ld\n", memo_num[i], memo_steps[i]); 
    } 
}

int64_t fib_memo(int user_num)
{
   if (memo_num == NULL)
   {
      memo_num = (int64_t *)malloc((MAX_SIZE) * sizeof(int64_t));
      memo_steps = (int64_t *)malloc((MAX_SIZE) * sizeof(int64_t));
      
      for (int i = 0; i < 1000; i++)
      {
         memo_num[i] = -1;
      }
   }

   if (memo_num[user_num] == -1)
   {
      memo_num[user_num] = collatz(user_num);
      //printf("Adding to cache: %d\n", user_num);
   }
   /*else
   {
      printf("Recieving from cache: %d\n", user_num);
   }
    */
   return memo_num[user_num];
}

int memo(int random, char policy[])
{
    for (int i = 0; i < 1000; i++)
      {
         memo_num[i] = -1;
      }
}
#endif //map
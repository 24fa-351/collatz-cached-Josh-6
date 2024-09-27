#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

typedef int64_t (*Functionpointer)(int);
Functionpointer fib_provider = NULL;

int64_t collatz(int64_t number)
{
    if (number % 2 == 0)
    {
        return number/2;
    }
    else
    {   
        return (3 * number) + 1;
    }

    return number;
}

int64_t step_counter(int num)
{
    int steps = 0;

    while (num != 1)
    {
        num = collatz(num);
        steps++;
    }

    return steps;
}

int64_t *memo = NULL;
int64_t fib_memo(int user_num)
{
   if (memo == NULL)
   {
      memo = (int64_t *)malloc((1000) * sizeof(int64_t));
      
      for (int i = 0; i < 1000; i++)
      {
         memo[i] = -1;
      }
   }


   if (memo[user_num] == -1)
   {
      memo[user_num] = collatz(user_num);
      //printf("Adding to cache: %d\n", user_num);
   }
   /*else
   {
      printf("Recieving from cache: %d\n", user_num);
   }*/

   return memo[user_num];
}

int main(int argc, char *argv[])
{

    int num_of_rand = atoi(argv[1]);
    int min = atoi(argv[2]);
    int max = atoi(argv[3]);

    int steps = 0;
    int total = 0;

    for(int i = 0; i < num_of_rand; i++)
    {
        int random_num = rand() % (max - min + 1) + min;
        steps = step_counter(random_num);
        total += steps;
        //printf("Number of steps for %d: %d\n", random_num, steps);
    }
    int avg_steps = total/num_of_rand;
    printf("Average steps: %d\n", avg_steps);

    //with cache
    /*
    for(int i = 0; i < num_of_rand; i++)
    {
        int random_num = rand() % (max - min + 1) + min;
        memo = fib_provider;
        //steps = fib_provider(random_num);
    }
    */
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
//#include "map.h"
#include "collatz_calc.h"

int64_t collat(int64_t number)
{
    if (number % 2 == 0)
    {
        return number/2;
    }
    else
    {   
        return (3 * number) + 1;
    }
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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include "map.h"
#include "collatz_calc.h"

int64_t collat(int64_t number)
{
    if (number % 2 == 0)
    {
        return number / 2;
    }
    else
    {
        return (3 * number) + 1;
    }
}

int64_t step_counter(int num)
{
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


    int total = 0;
    if (argc == 4)
    {
        for (int i = 0; i < num_of_rand; i++)
        {
            int random_num = rand() % (max - min + 1) + min;
            steps = step_counter(random_num);
            total += steps;
            //printf("Number of steps: %d\n", steps);
        }
        int avg_steps = total / num_of_rand;
        printf("Average steps: %d\n", avg_steps);
        printf("Size of char: %d\n", argc);
    }
    else if(argc == 6)
    {
        // with cache 
        steps = memoize(num_of_rand, max, min, argv[4], atoi(argv[5]));
        
    }
    else
    {
        printf("To many arguments");
    }
    return 0;
}
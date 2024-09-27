#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>


int64_t collatz(int64_t number)
{
    if (number % 2 == 0)
    {
        //number /= 2;
        return number/2;
    }
    else
    {   
        //number = (3*number) + 1;
        return (3 * number) + 1;
    }
}

int step_counter();

int main(int argc, char *argv[])
{

    int num_of_rand = atoi(argv[1]);
    int min = atoi(argv[2]);
    int max = atoi(argv[3]);

    int steps = 0;
    
    return 0;
}
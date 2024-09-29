#ifndef collatz_calc
#define collatz_calc
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
#include <inttypes.h>

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
}

#endif //collatz_calc
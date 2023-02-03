/*
 * Written by Dr Maryam Abo-Tabik
*/ 

#include <stdio.h>


/* the function return number based on even/odd test*/
int test(unsigned int x)
{
    /* write your code here*/
}

/* the function return the length of the sequnce*/
int count_length(unsigned int x)
{
    /* write your code here*/
}

int main(int argc, char* argv[])
{
    unsigned int i, init = 0, count = 0;

    for (i = 1; i < 100000000; i++)
    {
        unsigned int k = count_length(i);
        
        if (k > count)
        {
            count = k;
            init = i;
            printf("The sequence length for the number %u equals %u \n", init, count);
        }
    }

    return 0;
}

//
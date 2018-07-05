/**
  * Program to find all prime factors of a given number
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/**
 * timespec_diff() - returns time difference in milliseconds for two timespecs.
 * @stop:	time after event.
 * @start:	time before event.
 *
 * Uses difftime() for time_t seconds calcultation.
 */
double timespec_diff(struct timespec *stop, struct timespec *start)
{
	double diff = difftime(stop->tv_sec, start->tv_sec);
	diff *= 1000;
	diff += (stop->tv_nsec - start->tv_nsec) / 1e6;
	return diff;
}


int main(int argc, char *argv[])
{
	int i, j, num, isPrime;
	struct timespec time_now, time_after;
	
	/* Parse arguments */
	if (argc < 2)
		{
	 		goto exc_noargs;
		}
	if (argc == 2) 
		{
			num = atol(argv[1]);
		}
	if (argc > 2)
		{
			goto exc_argtoomuch;
		}
	
	printf("All Prime Factors of %d are: \n", num);
	
	/* Start searching */
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time_now);

	/* Find all Prime factors */
	for (i = 1; i <= num; i++)
    {
       	 /* Check 'i' for factor of num */
	    if(num%i==0)
       	{
            /* Check 'i' for Prime */
            isPrime = 1;
            for (j = 2; j <= i/2; j++)
           	{
                if(i%j == 0)
               	{
                    isPrime = 0;
                   	break;
                }
             }

           	/* If 'i' is Prime number and factor of num */
            if(isPrime == 1)
           	{
                printf("%d ", i);
           	}
		}
     }
    		
	/* Stop searching */
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time_after);
	printf(" \n");
		
	

	/* Print measured sorting time */
	printf("Searching Prime Factors of %d took %g ms\n", 
	       num, timespec_diff(&time_after, &time_now));
	return 0;

	/* Exception handling */
	exc_noargs:
	printf("Error: no arguments provided\n");
	return 1;

	exc_argtoomuch:
	printf("Error: too much arguments\n");
	return 1;
	
}

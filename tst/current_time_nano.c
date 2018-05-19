/* localtime example */
#include <stdio.h>
#include <time.h>

int main ()
{
    struct timespec tstart={0,0};
    clock_gettime(CLOCK_MONOTONIC, &tstart);

	printf("some_long_computation took about %f seconds\n", ((double)tstart.tv_sec + 1.0e-9*tstart.tv_nsec));

  	return 0;
}
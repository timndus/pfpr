#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main(int argc, char** argv) {
    struct timespec tstart;
	
    sleep(5);
    for(int j = 0; j < 4; j++)
    {	
        clock_gettime (CLOCK_REALTIME, &tstart);
	printf("some_long_computation took about %f seconds\n", ((double)tstart.tv_sec + 1.0e-9*tstart.tv_nsec));
	
	for(long i = 0; i < 2000000000; i++)
	{
		
	}
	sleep(2);
    }
    return 0;
}

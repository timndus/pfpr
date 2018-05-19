#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>


void* DoWork(void* args)
{
	double limit = 3000000000;
	/*switch(sched_getcpu())
	{
		case 0:
			limit = 1000000000;
			break;
		
		case 1:
			limit = 2000000000;
			break;
		
		case 2:
			limit = 3000000000;
		break;

		case 3:
			limit = 4000000000;
		break;
	}*/

	struct timespec begin, end;
	double elapsed;

	clock_gettime(CLOCK_MONOTONIC, &begin);

	for (double i = 0; i < limit; i++)
	{
		
	}

	clock_gettime(CLOCK_MONOTONIC, &end);

	elapsed = end.tv_sec - begin.tv_sec;
	elapsed += (end.tv_nsec - begin.tv_nsec) / 1000000000.0;

	int my_index = sched_getcpu();
    printf("CPU index: %d | Executed in: %lf\n", my_index, elapsed);

    return 0;
}

int main(int argc, char *argv[])
{   
    int numberOfProcessors = sysconf(_SC_NPROCESSORS_ONLN);
    printf("Number of processors: %d\n", numberOfProcessors);

    pthread_t threads[numberOfProcessors];

    pthread_attr_t attr;
    cpu_set_t cpus;
    pthread_attr_init(&attr);

    for (int i = 0; i < numberOfProcessors; i++) {
       CPU_ZERO(&cpus);
       CPU_SET(i, &cpus);
       pthread_attr_setaffinity_np(&attr, sizeof(cpu_set_t), &cpus);
       pthread_create(&threads[i], &attr, DoWork, NULL);
    }

    for (int i = 0; i < numberOfProcessors; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sched.h>
#include <time.h>

int main(int argc, char *argv[])
{
	int cores_num = atoi(argv[1]);
	cpu_set_t cpu_set;
	CPU_ZERO(&cpu_set);
	CPU_SET(cores_num, &cpu_set);
	sched_setaffinity(getpid(), sizeof(cpu_set_t), &cpu_set);

	clock_t begin = clock();

	for(unsigned int i = 0; i < 4000000000; i++)
	{
		//printf("%d!\n", i);
	}

	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("%ld\n", CLOCKS_PER_SEC);
	printf("%lf\n", time_spent);
	
	return 0;
}

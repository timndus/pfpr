#define _GNU_SOURCE         /* See feature_test_macros(7) */
#include <unistd.h>
#include <stdio.h>
#include <sched.h>

int main(void)
{
   printf("My process ID : %d\n", getpid());
   printf("My parent's ID: %d\n", getppid());
	int cpu_id = 0;
	cpu_id = sched_getcpu();
	printf("%d\n", cpu_id);

   return 0;
}

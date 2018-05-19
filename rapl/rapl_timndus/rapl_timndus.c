#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <sched.h>

#define SAMPLE_COUNT 50000
int main(int argc, char *argv[])
{
	cpu_set_t cpu_set;
	CPU_ZERO(&cpu_set);
	CPU_SET(atoi(argv[1]), &cpu_set);
	sched_setaffinity(getpid(), sizeof(cpu_set_t), &cpu_set);

	struct timespec start_time[SAMPLE_COUNT];
	struct timespec end_time[SAMPLE_COUNT];

 	FILE *ptr;
	char cmd[] = "cat /sys/class/powercap/intel-rapl/intel-rapl:0/energy_uj";

 	FILE *ptr_arr[SAMPLE_COUNT];
 	char energy_uj[SAMPLE_COUNT][16];
	int time_index = 0;

 	//sampling
 	int i = 0;
 	while (i < SAMPLE_COUNT)
 	{
	    clock_gettime(CLOCK_REALTIME, &start_time[time_index]);
		ptr_arr[i] = popen(cmd, "r");
		fscanf(ptr_arr[i], "%s", &energy_uj[i][0]);
	    clock_gettime(CLOCK_REALTIME, &end_time[time_index]);
		pclose(ptr_arr[i]);
		i++;
		time_index++;
 	}

	FILE *time_log;
	FILE *energy_uj_log;
	char log_dir[] = "/home/timndus/code/rapl_timndus/log/";
	time_log = fopen(strcat(log_dir, "time.log"), "w");
	energy_uj_log = fopen(strcat(log_dir, "energy_uj.log"), "w");


	long int saved_in = 0;
	long int sample_rate = 0;
 	//presentation
	for (int i = 0; i < SAMPLE_COUNT; i++)
 	{
		saved_in = 0;
		sample_rate = 0;

		if(start_time[i+1].tv_nsec > start_time[i].tv_nsec)
		{
			sample_rate = start_time[i+1].tv_nsec - start_time[i].tv_nsec;
		}
		else
		{
			sample_rate = (999999999 - start_time[i].tv_nsec) + (start_time[i+1].tv_nsec);
		}

		if(end_time[i].tv_nsec > start_time[i].tv_nsec)
		{
			saved_in = end_time[i].tv_nsec - start_time[i].tv_nsec;
		}
		else
		{
			saved_in = (999999999 - start_time[i].tv_nsec) + (end_time[i].tv_nsec);
		}
		
 		printf("%d:\tenergy_uj: %s | s_time_n: %lu | e_time_n: %lu | s_time_second: %lu | s_time_s_rounded: %lu | s_time_sn: %lu | saved_in: %lu | my_s_rate: %lu\n", i, energy_uj[i], start_time[i].tv_nsec, end_time[i].tv_nsec, start_time[i].tv_sec, start_time[i].tv_sec%100, start_time[i].tv_sec%10 * 1000000 + start_time[i].tv_nsec/1000, saved_in, sample_rate);

		//fprintf(time_log, "%lu\n", start_time[i].tv_sec%100 * 1000000 + start_time[i].tv_nsec/1000);
		fprintf(time_log, "%lu%s%lu\n", start_time[i].tv_sec%100, ".", start_time[i].tv_nsec);
		fprintf(energy_uj_log, "%s\n", energy_uj[i]);

 	}

	fclose(time_log);
	fclose(energy_uj_log);

/**/
    return 0;
}

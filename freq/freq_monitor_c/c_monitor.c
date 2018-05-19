#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <sched.h>

#define SAMPLE_COUNT 60
int main(int argc, char *argv[])
{
	cpu_set_t cpu_set;
	CPU_ZERO(&cpu_set);
	CPU_SET(atoi(argv[1]), &cpu_set);
	sched_setaffinity(getpid(), sizeof(cpu_set_t), &cpu_set);

	struct timespec start_time[SAMPLE_COUNT];
	struct timespec end_time[SAMPLE_COUNT];

 	int cpu_count  = 4;
 	FILE *ptr;
 	ptr = popen("nproc", "r");
 	fscanf(ptr, "%d", &cpu_count);
 	//printf("%d\n", cpu_count);

	int cpuinfo_max_freq [4];
 	char cmd_prefix[] = "cat /sys/devices/system/cpu/cpufreq/policy";
 	char cmd[cpu_count][62];
 	for (int i = 0; i < cpu_count; i++)
 	{
 		sprintf(cmd[i], "%s%d%s", cmd_prefix, i, "/cpuinfo_max_freq");
		ptr = popen(cmd[i], "r");
		fscanf(ptr, "%d", &cpuinfo_max_freq[i]);
 		//printf("cpu_index: %d\tcpuinfo_max_freq: %d\n", i, cpuinfo_max_freq[i] );
 		sprintf(cmd[i], "%s%d%s", cmd_prefix, i, "/cpuinfo_cur_freq");
 	}
	pclose(ptr);

 	FILE *ptr_arr[SAMPLE_COUNT];
 	int cpuinfo_cur_freq[SAMPLE_COUNT];
 	int cpu_index = 0;
 	int time_index = 0;

 	//sampling
 	int i = 0;
 	while (i < SAMPLE_COUNT)
 	{
	    clock_gettime(CLOCK_REALTIME, &start_time[time_index]);
		ptr_arr[i] = popen(cmd[i%4], "r");
		fscanf(ptr_arr[i], "%d", &cpuinfo_cur_freq[i]);
	    clock_gettime(CLOCK_REALTIME, &end_time[time_index]);
		pclose(ptr_arr[i]);
		i++;
		time_index++;
		//usleep(150000);
 	}

	FILE *time_log[cpu_count];
	FILE *freq_log[cpu_count];
	char time_log_dir_prefix[] = "log/time_";
	char freq_log_dir_prefix[] = "log/freq_";
	char log_dir[16];
	for (int i = 0; i < cpu_count; i++)
	{
		sprintf(log_dir, "%s%d%s", time_log_dir_prefix, i, ".log");
		time_log[i] = fopen(log_dir, "w");
		sprintf(log_dir, "%s%d%s", freq_log_dir_prefix, i, ".log");
		freq_log[i] = fopen(log_dir, "w");
	}

	unsigned long saved_in = 0;
	unsigned long sample_rate = 0;
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
 		printf("s_id: %d\tcpu_index: %d\ts_c_freq: %d\ts_time_n: %lu\te_time_n: %lu\ts_time_s: %lu\ts_time_sn: %lu\tsaved_in: %lu\tmy_s_rate: %lu\n", i, i%4, cpuinfo_cur_freq[i], start_time[i].tv_nsec, end_time[i].tv_nsec, start_time[i].tv_sec%10, start_time[i].tv_sec%10 * 1000000 + start_time[i].tv_nsec/1000, saved_in, sample_rate);

		fprintf(time_log[i%4], "%lu\n", start_time[i].tv_sec%100 * 1000000 + start_time[i].tv_nsec/1000);
		fprintf(freq_log[i%4], "%d\n", cpuinfo_cur_freq[i]);

 	}

 	for (int i = 0; i < cpu_count; i++)
 	{
		fclose(time_log[i]);
		fclose(freq_log[i]);
 	}

	for (int i = 0; i < SAMPLE_COUNT; i++)
 	{
		if(cpuinfo_cur_freq[i] == cpuinfo_max_freq[atoi(argv[1])])
		{
			printf("time_to_max_freq: %lu\n", start_time[i].tv_nsec - start_time[0].tv_nsec);
			break;
		}
	}

/**/
    return 0;
}


#include <stdio.h>
#include <stdlib.h> // For exit() function
#include <time.h>

#define SIZE 50000 

int main(int argc, char *argv[])
{
/*    time_t current_time;
    char *c_time_string;
    current_time = time(NULL);
    c_time_string = ctime(&current_time);
    printf("current time is: %s\n", c_time_string);
    printf("raw time is: %ld\n", (long)current_time);
*/
    struct timespec current_time[SIZE];
    clock_gettime(CLOCK_REALTIME, &current_time[0]);
    
    for (unsigned int i = 0; i < 4000000000; i++)
    {
    
    }
    
    clock_gettime(CLOCK_REALTIME, &current_time[1]);

    printf("Start: %lu | Stop: %lu | Executed In: %lu\n", current_time[0].tv_nsec, current_time[1].tv_nsec,  current_time[1].tv_nsec - current_time[0].tv_nsec);


    /*char c[SIZE][20];
    FILE *fptr;

    for (int i = 0; i < SIZE; i++)
    {
        if ((fptr = fopen("/sys/devices/system/cpu/cpu0/cpufreq/cpuinfo_cur_freq", "r")) == NULL)
        {
            printf("Error! opening file");
            // Program exits if file pointer returns NULL.
            exit(1);         
        }

        clock_gettime(CLOCK_REALTIME, &current_time[i]);
    
        fscanf(fptr,"%[^\n]", &c[i][0]);
        //printf("Data from the file %d:%s\n", i, c);
        fclose(fptr);

    }

    for (int i = 0; i < SIZE; i++)
    {
        printf("Time is: %lu | Executed in: %lu | freq is: %s\n", current_time[i].tv_nsec, current_time[i].tv_nsec - current_time[i-1].tv_nsec, c[i]);
    }*/
    
    return 0;
}
#include <stdlib.h>
#include "stdio.h"
#include <string.h>
#define LEN 256

int main()
{
/* Get the the current process' stat file from the proc filesystem */
        FILE* procfile = fopen("/proc/self/stat", "r");
        long to_read = 8192;
        char buffer[to_read];
        int read = fread(buffer, sizeof(char), to_read, procfile);
        fclose(procfile);

        // Field with index 38 (zero-based counting) is the one we want
        char* line = strtok(buffer, " ");
        for (int i = 1; i < 38; i++)
        {
            line = strtok(NULL, " ");
        }

        line = strtok(NULL, " ");
        int cpu_id = atoi(line);

        FILE * fp;
        char scaling_setspeed_dir[60];
        sprintf(scaling_setspeed_dir,"%s%d%s", "/sys/devices/system/cpu/cpu", cpu_id, "/cpufreq/scaling_setspeed");
        fp = fopen (scaling_setspeed_dir,"w");
        fprintf(fp, "933000");
        fclose (fp);
}

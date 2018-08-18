#include <stdio.h>
#include <string.h>
#include <dirent.h>

#define CORE_STRING_MAX 3
#define CORE_MAX 16

int main()
{
	DIR *cpu_dir_ptr;
    char cpu_dir_prefix[80] = "/sys/devices/system/cpu/cpu";
    char cpu_dir_suffix[10] = "/cpufreq/";
    char cur_dir[100];
    int core_index = 0;
    int core_cnt = 0;

    FILE *scaling_available_frequencies_ptr[CORE_MAX];

	char cmd_string[3];
	int cmd = 0;
	char core_string[CORE_STRING_MAX];
	int core[CORE_MAX] = {-1};
	int core_tmp = -1;
	int core_index = 0;

	printf("0: Exit |  1: Set freq\n");

	fgets(cmd_string, 3, stdin);
	sscanf(cmd_string, "%d", &cmd);

	switch(cmd)
	{
		case 1:
			printf("Online cores:\n");
			core_index = 0;
		    while(core_index < CORE_MAX)
		    {
		        sprintf(cur_dir, "%s%d%s", cpu_dir_prefix, core_index, cpu_dir_suffix);
		        cpu_dir_ptr = opendir(cur_dir);
		        if(cpu_dir_ptr == NULL)
		        {
		            //printf("cpu numbers: %d\n", core_index);
		        	core_cnt = core_index;
		            break;
		        }
		        else
		        {
		            printf("%d\t", core_index);
		            closedir(cpu_dir_ptr);
		        }
		        core_index++;
		    }
			printf("\n-2: Select all cores, -1: Done\nEnter core index:\n");
			core_index = 0;
			while (1)
			{
				fgets(core_string, CORE_STRING_MAX, stdin);
				if(!sscanf(core_string, "%d", &core[core_index++]))
				{
					core_index--;
					break;	
				}
				else
				{
					if(core[core_index-1] == -1)
					{
						core_index--;
						break;
					}
					else
					{
						if(core[core_index-1] == -2)
						{

						}
					}
				}
			}



			for (int i = 0; i < core_index; i++)
			{
				printf("%d\n", core[i]);
				
			}

			break;

		case 0:
			return 0;
	}
	return 0;
}
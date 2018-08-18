#include <stdio.h>
#include <time.h>

int main()
{
	printf("start\n");
	struct timespec ts = {0, 900000000L };
	nanosleep (&ts, NULL);
	printf("end\n");
	return 0;
}

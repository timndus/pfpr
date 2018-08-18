#include <stdlib.h>
#include "stdio.h"

int main()
{	
	int a = 4;
	FILE * fp;
        fp = fopen ("/home/timndus/log","w");
        fprintf(fp, "%d", a);
	fclose (fp);
}

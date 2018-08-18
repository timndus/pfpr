#include <stdio.h>
#include <stdlib.h>

#ifndef FILE_2
#define FILE_2
#include "file2.h"
#endif

#ifndef FILE_2
#define FILE_2
#include "file2.h"
#endif


int main()
{
	printf("%d", bar(6));
}

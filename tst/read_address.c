#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *a;
	a = (int *)0x7ffdd4cfe3e4;
	printf("%d", *a);

	return 0;
}

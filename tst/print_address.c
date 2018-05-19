#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a = 4;
	printf("%p\n", &a);

	int *p;
	p = (int *)&a;
	printf("%d", *p);

	return 0;
}

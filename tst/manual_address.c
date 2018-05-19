#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *var = (int*)0x04000000;
	*var = 4;
	
	return 0;
}

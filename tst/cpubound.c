#include <stdlib.h>
#include <stdio.h>

#define	SIZE	5000
int main()
{
	double arr[SIZE];
	for (int i = 0; i < SIZE; i++)
	{
		arr[i] = i;
	}

	for (int j = 0; j < 1000000; j++)
	{
		/* code */
		for (int i = 0; i < SIZE - 1; ++i)
		{
			arr[i] = arr[i] + arr[i + 1];
		}
	}
	return 0;
}
#include <stdio.h>
#include <stdlib.h>

void __set_var(int *var);

int main()
{
	int foo = 4;
	__set_var(&foo);
	//printf("%d\n", foo);
	return 0;
}

void __set_var(int *var)
{
	/*char str[20] = "1234";
    sscanf(str, "%d", var);
	*/
	//*var = 5;
	int a;
	a = *var;

	printf("%d\n", a);
}
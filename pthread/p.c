#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sched.h>

#define	BUF_SIZE	500

void *print_message_function( void *ptr );
void *func2( void *ptr  );
int a;
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;



int main()
{
	/*cpu_set_t cpu_set;
	CPU_ZERO(&cpu_set);
	CPU_SET(0, &cpu_set);
	sched_setaffinity(getpid(), sizeof(cpu_set_t), &cpu_set);	
    */
    pthread_t thread1, thread2;
    const char *message1 = "thread 1 msg";
    int var1 = 65;
    int  iret1, iret2;

	a = 0;
    /* Create independent threads each of which will execute function */

     iret1 = pthread_create( &thread1, NULL, print_message_function, (void*) message1);
     if(iret1)
     {
         fprintf(stderr,"Error - pthread_create() return code: %d\n",iret1);
         exit(EXIT_FAILURE);
     }

     iret2 = pthread_create( &thread2, NULL, func2, (void*) &var1);
     if(iret2)
     {
         fprintf(stderr,"Error - pthread_create() return code: %d\n",iret2);
         exit(EXIT_FAILURE);
     }


//	printf("before: %d\n", a);
     pthread_join( thread1, NULL);
//     pthread_join( thread2, NULL);
//	printf("after: %d\n", a); 

     exit(EXIT_SUCCESS);
}

void *print_message_function( void *ptr )
{
    cpu_set_t cpu_set;
    CPU_ZERO(&cpu_set);
    CPU_SET(2, &cpu_set);
    sched_setaffinity(getpid(), sizeof(cpu_set_t), &cpu_set);
    /*     char *message;
     message = (char *) ptr;
     printf("%s \n", message);
     */
//	pthread_mutex_lock( &mutex1 );
	unsigned int i = 0;
    while(i < 1000000000)
    {
        i++;
    }
//	pthread_mutex_unlock( &mutex1 );

}

void *func2( void *ptr  )
{
    cpu_set_t cpu_set;
    CPU_ZERO(&cpu_set);
    CPU_SET(3, &cpu_set);
    sched_setaffinity(getpid(), sizeof(cpu_set_t), &cpu_set);

    unsigned int j = 0;
    while(j < 4000000000)
    {
        j++;
    }
	/*for(int i = 0; i < 30; i++)
	{
		printf("%d\n", i);
	}*/
	//printf("%d\n", *(int*)ptr);
//	pthread_mutex_lock( &mutex1 );
	/*int b = 0;
	char buf[BUF_SIZE];
	while(1)
	{
		b++;
		sprintf(buf, "b val is: %d\n", b);
		write(1, buf, strlen(buf));
	}
    */
//	pthread_mutex_unlock( &mutex1 );
}


















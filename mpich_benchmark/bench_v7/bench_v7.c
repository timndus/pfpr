#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LOOP 2000000000

/*
#define LOOP4_4	4000000000
#define LOOP3_4 3000000000
#define LOOP2_4 2000000000
#define LOOP1_4 1000000000
*/

void to_do(int repeat);

int main(int argc, char** argv)
{
	struct timespec tstart;
	struct timespec tend;
	clock_gettime (CLOCK_REALTIME, &tstart);

	MPI_Init(NULL, NULL);
	int flag = 0;
	int world_rank;
	MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
	int world_size;
	MPI_Comm_size(MPI_COMM_WORLD, &world_size);

	if (world_size < 6)
	{
		fprintf(stderr, "World size must be greater than 6 for %s\n", argv[0]);
		MPI_Abort(MPI_COMM_WORLD, 1);
	}

	int number = -1;
	int recv_source;
	int send_source;
	int steps = 7;

	if(world_rank == 0)
	{
		recv_source = 1;
		send_source = 5;

//		printf("[%d] loop A start\n", world_rank);
		to_do(world_rank + 1);
//		printf("[%d] loop A end => request to [%d] start\n", world_rank, recv_source);
		MPI_Recv(&number, 1, MPI_INT, recv_source, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
//	    	printf("[%d] response from [%d] => loop B start\n", world_rank, recv_source);

		to_do(5);
//		printf("[%d] loop B end => send response to [%d]\n", world_rank, send_source);
	   	MPI_Send(&number, 1, MPI_INT, send_source, 0, MPI_COMM_WORLD);
//		printf("[%d] core is done\n", world_rank);
	}
	else
	{
		if(world_rank == 5)
		{
			recv_source = 0;
			send_source = 4;

//			printf("[%d] loop A start\n", world_rank);
			to_do(world_rank + 1);
//			printf("[%d] loop A end => send response to [%d] and request to [%d] start\n", world_rank, send_source, recv_source);
		   	MPI_Send(&number, 1, MPI_INT, send_source, 0, MPI_COMM_WORLD);
		    	MPI_Recv(&number, 1, MPI_INT, recv_source, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
//			printf("[%d] response from [%d] => core is done\n", world_rank, recv_source);
		}
		else
		{
			recv_source = world_rank + 1;
			send_source = world_rank - 1;
//			printf("[%d] loop A start\n", world_rank);
			to_do(world_rank + 1);
//			printf("[%d] loop A end => send response to [%d] and request to [%d] start\n", world_rank, send_source, recv_source);

		   	MPI_Send(&number, 1, MPI_INT, send_source, 0, MPI_COMM_WORLD);
		    	MPI_Recv(&number, 1, MPI_INT, recv_source, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

//		    	printf("[%d] response from [%d] => loop B start\n", world_rank, recv_source);
			to_do(steps - world_rank - 1 - 1);
//			printf("[%d] loop B end => core is done\n", world_rank);
		}
	}

	clock_gettime (CLOCK_REALTIME, &tend);
	long int t = (tend.tv_sec * 1000000000 + tend.tv_nsec) - (tstart.tv_sec * 1000000000 + tstart.tv_nsec);
	
	MPI_Finalize();
	printf("[%d]: %ld.%ld\n", world_rank, t / 1000000000, t % 1000000000 );
}

void to_do(int repeat)
{
	for (int i = 0; i < repeat; i++)
	{
		for (double j = 0; j < LOOP; j++)
		{
			/* code */
		}
	}
}

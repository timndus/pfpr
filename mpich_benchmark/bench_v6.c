#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LOOP4_4	4000000000
#define LOOP3_4 3000000000
#define LOOP2_4 2000000000
#define LOOP1_4 1000000000

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

	if (world_size < 4)
	{
		fprintf(stderr, "World size must be greater than 3 for %s\n", argv[0]);
		MPI_Abort(MPI_COMM_WORLD, 1);
	}

	int number;
	if (world_rank == 0)
	{
		number = -1;
		printf("[%d] loop A start\n", world_rank);
		for(double i = 0; i < LOOP1_4; i++){}
		printf("[%d] loop A end\n", world_rank);

		printf("[%d] recv for [1]\n", world_rank);
	    MPI_Recv(&number, 1, MPI_INT, 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

	    printf("[%d] loop B start\n", world_rank);
		for(double i = 0; i < LOOP1_4; i++){}
		printf("[%d] loop B end\n", world_rank);

		printf("[%d] send to [3]\n", world_rank);
	   	MPI_Send(&number, 1, MPI_INT, 3, 0, MPI_COMM_WORLD);

	    printf("[%d] loop C start\n", world_rank);
		for(double i = 0; i < LOOP1_4; i++){}
		printf("[%d] loop C end\n", world_rank);

		printf("[%d] program end\n\n", world_rank);
	}
	else
	{
		if (world_rank == 1)
		{
			number = -1;
			printf("[%d] loop A start\n", world_rank);
			for(double i = 0; i < LOOP2_4; i++){}
			printf("[%d] loop A end\n", world_rank);

			printf("[%d] recv for [2]\n", world_rank);
		    MPI_Recv(&number, 1, MPI_INT, 2, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

		    printf("[%d] loop B start\n", world_rank);
			for(double i = 0; i < LOOP1_4; i++){}
			printf("[%d] loop B end\n", world_rank);

			printf("[%d] send to [0]\n", world_rank);
		   	MPI_Send(&number, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);

		    printf("[%d] loop C start\n", world_rank);
			for(double i = 0; i < LOOP2_4; i++){}
			printf("[%d] loop C end\n", world_rank);

			printf("[%d] program end\n\n", world_rank);
		}
		else
		{
			if (world_rank == 2)
			{				
				number = -1;
				printf("[%d] loop A start\n", world_rank);
				for(double i = 0; i < LOOP3_4; i++){}
				printf("[%d] loop A end\n", world_rank);

				printf("[%d] recv for [3]\n", world_rank);
			    MPI_Recv(&number, 1, MPI_INT, 3, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

			    printf("[%d] loop B start\n", world_rank);
				for(double i = 0; i < LOOP1_4; i++){}
				printf("[%d] loop B end\n", world_rank);

				printf("[%d] send to [1]\n", world_rank);
			   	MPI_Send(&number, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);

			    printf("[%d] loop C start\n", world_rank);
				for(double i = 0; i < LOOP3_4; i++){}
				printf("[%d] loop C end\n", world_rank);

				printf("[%d] program end\n\n", world_rank);
			}
			else
			{
				if(world_rank == 3)
				{
					number = -1;
					printf("[%d] loop A start\n", world_rank);
					for(double i = 0; i < LOOP4_4; i++){}
					printf("[%d] loop A end\n", world_rank);

					printf("[%d] send to [2]\n", world_rank);
				   	MPI_Send(&number, 1, MPI_INT, 2, 0, MPI_COMM_WORLD);

					printf("[%d] recv for [0]\n", world_rank);
				    MPI_Recv(&number, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

				    printf("[%d] loop B start\n", world_rank);
					for(double i = 0; i < LOOP1_4; i++){}
					printf("[%d] loop B end\n", world_rank);

					printf("[%d] program end\n\n", world_rank);
				}
			}
		}
	}
	MPI_Finalize();
	clock_gettime (CLOCK_REALTIME, &tend);
	long int t = (tend.tv_sec * 1000000000 + tend.tv_nsec) - (tstart.tv_sec * 1000000000 + tstart.tv_nsec);
	printf("%ld.%ld\n", t / 1000000000, t % 1000000000 );
	
}


















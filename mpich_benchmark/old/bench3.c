#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char** argv)
{
	struct timespec tstart;
	struct timespec tend;
	clock_gettime (CLOCK_REALTIME, &tstart);

	MPI_Init(NULL, NULL);
	MPI_Status status;
	int flag = 0;
	int world_rank;
	MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
	int world_size;
	MPI_Comm_size(MPI_COMM_WORLD, &world_size);

	if (world_size < 3)
	{
		fprintf(stderr, "World size must be greater than 2 for %s\n", argv[0]);
		MPI_Abort(MPI_COMM_WORLD, 1);
	}

	int number;
	if (world_rank == 0)
	{
		number = -1;
		printf("[%d] loop started\n", world_rank);
		for(double i = 0; i < 3000000000; i++){}
		printf("[%d] loop end\n", world_rank);


		//MPI_Iprobe( 1, 0, MPI_COMM_WORLD, &flag, &status );
		//printf("[%d] flag is: %d\n", world_rank, flag );			


		printf("[%d] send start to [1]\n", world_rank);
    	MPI_Send(&number, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
		
		printf("[%d] send start to [2]\n", world_rank);
    	MPI_Send(&number, 1, MPI_INT, 2, 0, MPI_COMM_WORLD);

/*
		printf("[%d] recv start from [1]\n", world_rank);
	    MPI_Recv(&number, 1, MPI_INT, 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

		printf("[%d] recv start from [2]\n", world_rank);
	    MPI_Recv(&number, 1, MPI_INT, 2, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
*/
		//MPI_Recv(&number, 1, MPI_INT, 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		printf("[%d] code end======================\n", world_rank);
	}
	else
	{
		if (world_rank == 1)
		{
			number = -1;
			printf("[%d] loop started\n", world_rank);
			for(double i = 0; i < 1000000000; i++){}
			printf("[%d] loop end\n", world_rank);


			//MPI_Iprobe( 1, 0, MPI_COMM_WORLD, &flag, &status );
			//printf("[%d] flag is: %d\n", world_rank, flag );			
/*
			printf("[%d] send start to [0]\n", world_rank);
	    	MPI_Send(&number, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
*/
/*			
			printf("[%d] send start to [2]\n", world_rank);
	    	MPI_Send(&number, 1, MPI_INT, 2, 0, MPI_COMM_WORLD);
*/

			printf("[%d] recv start from [0]\n", world_rank);
		    MPI_Recv(&number, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

/*
			printf("[%d] recv start from [2]\n", world_rank);
		    MPI_Recv(&number, 1, MPI_INT, 2, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
*/

			//MPI_Recv(&number, 1, MPI_INT, 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
			printf("[%d] code end======================\n", world_rank);
		}
		else
		{
			if (world_rank == 2)
			{				
				number = -1;
				printf("[%d] loop started\n", world_rank);
				for(double i = 0; i < 2000000000; i++){}
				printf("[%d] loop end\n", world_rank);


				//MPI_Iprobe( 1, 0, MPI_COMM_WORLD, &flag, &status );
				//printf("[%d] flag is: %d\n", world_rank, flag );			

/*
				printf("[%d] send start to [0]\n", world_rank);
		    	MPI_Send(&number, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
*/
/*				
				printf("[%d] send start to [1]\n", world_rank);
		    	MPI_Send(&number, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
*/

				printf("[%d] recv start from [0]\n", world_rank);
			    MPI_Recv(&number, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

/*
				printf("[%d] recv start from [1]\n", world_rank);
			    MPI_Recv(&number, 1, MPI_INT, 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
*/

				//MPI_Recv(&number, 1, MPI_INT, 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
				printf("[%d] code end======================\n", world_rank);
			}
		}
	}
	MPI_Finalize();
	clock_gettime (CLOCK_REALTIME, &tend);
	long int t = (tend.tv_sec * 1000000000 + tend.tv_nsec) - (tstart.tv_sec * 1000000000 + tstart.tv_nsec);
	printf("%ld.%ld\n", t / 1000000000, t % 1000000000 );
	
}


















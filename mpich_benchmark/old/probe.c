#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

#define LEN 256

int main(int argc, char** argv)
{
	MPI_Init(NULL, NULL);
	MPI_Status status;
	int flag = 0;
	int world_rank;
	MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
	int world_size;
	MPI_Comm_size(MPI_COMM_WORLD, &world_size);

	if (world_size < 2)
	{
		fprintf(stderr, "World size must be greater than 1 for %s\n", argv[0]);
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

		printf("[%d] send start\n", world_rank);
    	MPI_Send(&number, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
    	MPI_Send(&number, 1, MPI_INT, 2, 0, MPI_COMM_WORLD);
		//MPI_Recv(&number, 1, MPI_INT, 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		printf("[%d] send done\n", world_rank);
	}
	else
	{
		if (world_rank == 1)
		{
			printf("[%d] loop started\n", world_rank);
			for(double j = 0; j < 1000000000; j++){}
			printf("[%d] loop end\n", world_rank);

			//printf("[%d] recv start\n", world_rank);
			//MPI_Send(&number, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);   
		    MPI_Recv(&number, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
			printf("[%d] recv done\n", world_rank);
		}
		else
		{
			if (world_rank == 2)
			{
				printf("[%d] loop started\n", world_rank);
				for(double j = 0; j < 2000000000; j++){}
				printf("[%d] loop end\n", world_rank);

				//printf("[%d] recv start\n", world_rank);
				//MPI_Send(&number, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);   
			    MPI_Recv(&number, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
				printf("[%d] recv done\n", world_rank);
			}
		}
	}
	MPI_Finalize();
}


















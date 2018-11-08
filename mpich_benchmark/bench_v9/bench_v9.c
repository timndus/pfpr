#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void to_do(double val);

int main(int argc, char** argv)
{
	double computation = 400000000;
	double comm = 100000000;
	int comm_count = 3;
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
	int steps = 8;
	double comm_all;
	
	int repeat = 0;
	while (repeat < 1)
	{
		to_do(computation);
		if(world_rank == 0)
		{
			recv_source = 1;
			send_source = 5;

			to_do( 0 * computation );

			comm_all = 0;
			for (int i = 0; i < comm_count; i++)
			{
				MPI_Recv(&number, 1, MPI_INT, recv_source, i, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
				comm_all += comm;
			}
			to_do(computation - comm_all);
			to_do(4 * computation);

			comm_all = 0;
			for (int i = 0; i < comm_count; i++)
			{
				to_do(comm);
				MPI_Send(&number, 1, MPI_INT, send_source, i, MPI_COMM_WORLD);
				comm_all += comm;
			}
			to_do(computation - comm_all);
			to_do(computation);
		}
		else
		{
			if(world_rank == 5)
			{
				recv_source = 0;
				send_source = 4;

				to_do( (world_rank - 1) * computation );

				comm_all = 0;
				for (int i = 0; i < comm_count; i++)
				{
					to_do(comm);
					MPI_Send(&number, 1, MPI_INT, send_source, i, MPI_COMM_WORLD);
					comm_all += comm;
				}
				to_do(computation - comm_all);

				comm_all = 0;
				for (int i = 0; i < comm_count; i++)
				{
					MPI_Recv(&number, 1, MPI_INT, recv_source, i, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
					comm_all += comm;
				}
				to_do(computation - comm_all);
				to_do(computation);
			}
			else
			{
				recv_source = world_rank + 1;
				send_source = world_rank - 1;

				to_do( (world_rank - 1) * computation );

				comm_all = 0;
				for (int i = 0; i < comm_count; i++)
				{
					to_do(comm);
					MPI_Send(&number, 1, MPI_INT, send_source, i, MPI_COMM_WORLD);
					comm_all += comm;
				}
				to_do(computation - comm_all);

				comm_all = 0;
				for (int i = 0; i < comm_count; i++)
				{
				MPI_Recv(&number, 1, MPI_INT, recv_source, i, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
					comm_all += comm;
				}
				to_do(computation - comm_all);
				to_do( (steps - 2 - world_rank) * computation );
			}
		}
		repeat++;
	}
	
	clock_gettime (CLOCK_REALTIME, &tend);
	long int t = (tend.tv_sec * 1000000000 + tend.tv_nsec) - (tstart.tv_sec * 1000000000 + tstart.tv_nsec);
	
	MPI_Finalize();
	printf("[%d]: %ld.%ld\n", world_rank, t / 1000000000, t % 1000000000 );

}

void to_do(double val)
{
	for (double i = 0; i < val; i++)
	{
		/* code */
	}
}

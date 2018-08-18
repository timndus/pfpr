#include <mpi.h>
#include <stdio.h>

int main(int argc, char** argv) {
    MPI_Init(NULL, NULL);

    int world_size;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

    for (long i = 0; i < 4000000000; i++)
    {
    	if (i == 3000000000)
	{
		i = 0;
	}
    }

    MPI_Finalize();
}

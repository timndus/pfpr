#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char** argv) {
    struct timespec tstart;
    struct timespec tend;
    clock_gettime (CLOCK_REALTIME, &tstart);

    MPI_Init(NULL, NULL);

    int world_size;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

    for (long i = 0; i < 3000000000; i++)
    {
    	
    }

    MPI_Finalize();

    clock_gettime (CLOCK_REALTIME, &tend);
    long int t = (tend.tv_sec * 1000000000 + tend.tv_nsec) - (tstart.tv_sec * 1000000000 + tstart.tv_nsec);
    printf("%ld.%ld\n", t / 1000000000, t % 1000000000 );
}

#include "mpi.h"
#include <stdio.h>
 
int main(int argc, char *argv[])
{
    int myid, numprocs, left, right;
    int buffer[10], buffer2[10];
    MPI_Request request;
    MPI_Status status;
 
    MPI_Init(&argc,&argv);
    MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
    MPI_Comm_rank(MPI_COMM_WORLD, &myid);
 
    right = (myid + 1) % numprocs;
    left = myid - 1;
    if (left < 0)
        left = numprocs - 1;
 
    MPI_Irecv(buffer, 10, MPI_INT, left, 123, MPI_COMM_WORLD, &request);
    printf("%s\n", "MPI_Irecv called.");
    
    MPI_Send(buffer2, 10, MPI_INT, right, 123, MPI_COMM_WORLD);
    printf("%s\n", "MPI_Send called.");
    
    printf("%s\n", "MPI_Wait call start.");
    MPI_Wait(&request, &status);
    printf("%s\n", "MPI_Wait call end.");

    MPI_Finalize();
    return 0;
}
#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 5000

int main(int argc, char** argv)
{
  MPI_Init(NULL, NULL);
  int world_rank;
  MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
  int world_size;
  MPI_Comm_size(MPI_COMM_WORLD, &world_size);

  
  double arr[SIZE];
  for (int i = 0; i < SIZE; i++)
  {
    arr[i] = i;
  }

  for (int j = 0; j < 1000000; j++)
  {
    /* code */
    for (int i = 0; i < SIZE - 1; ++i)
    {
      arr[i] = arr[i] + arr[i + 1];
    }
  }

  MPI_Finalize();
}


















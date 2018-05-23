#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LEN 256

int main(int argc, char** argv)
{
  MPI_Init(NULL, NULL);
  int world_rank;
  MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
  int world_size;
  MPI_Comm_size(MPI_COMM_WORLD, &world_size);

  int i = 0;
  while(1)
  {
  	i++;
	if(i == 2000000)
	{
		i = 0;
	}
  }

  MPI_Finalize();
}


















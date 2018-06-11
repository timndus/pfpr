// Author: Wes Kendall
// Copyright 2011 www.mpitutorial.com
// This code is provided freely with the tutorials on mpitutorial.com. Feel
// free to modify it for your own use. Any distribution of the code must
// either provide a link to www.mpitutorial.com or keep this header intact.
//
// MPI_Send, MPI_Recv example. Communicates the number -1 from process 0
// to process 1.
//
#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LEN 256

int main(int argc, char** argv) {

	clock_t begin = clock();

  MPI_Init(NULL, NULL);
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
    // If we are rank 0, set the number to -1 and send it to process 1
    number = -1;
    printf("process 0 task started.\n");
    for(double i = 0; i < 2000000000; i++){}
    printf("process 0 task is done, i need more data from process 1, wating to recv from process 1 ...\n");
    //MPI_Send(&number, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
    MPI_Recv(&number, 1, MPI_INT, 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    printf("process 0 reporte: data received from proccess 1, so task can done.\n");

    for(double i = 0; i < 2000000000; i++){}
    
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("%ld\n", CLOCKS_PER_SEC);
    printf("%lf\n", time_spent);
    FILE * fp;
    fp = fopen ("/home/timndus/code/mpich_benchmark/execution_time.log","a");
    fprintf(fp,"%lf%s", time_spent ,"\n");
    fclose (fp);

  }
  else if (world_rank == 1)
  {
    printf("process 1 task started.\n");
    for(double j = 0; j < 4000000000; j++){}
    printf("process 1 task is done, i'm sending result to process 0 ...\n");
    MPI_Send(&number, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);   
    //MPI_Recv(&number, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    printf("proccess 1 report, send is done. so go to run my loop 2\n");

    for(double j = 0; j < 4000000000; j++){}
  }
  MPI_Finalize();
}


















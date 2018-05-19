#define _GNU_SOURCE         /* See feature_test_macros(7) */

#include <mpi.h>
#include <stdio.h>
#include <sched.h>

int main(int argc, char** argv) {
        int __TIM_world_rank;
        int __TIM_world_size;
        int __TIM_shared_info_arr[4] = {};
        int __TIM_shared_info = -2;

        MPI_Init(&argc, &argv);
        MPI_Comm_rank(MPI_COMM_WORLD, &__TIM_world_rank);
        MPI_Comm_size(MPI_COMM_WORLD, &__TIM_world_size);

        int __TIM_cpu_id = 0;
        __TIM_cpu_id = sched_getcpu();
        printf("[%d]: my __TIM_cpu_id is: %d\n",__TIM_world_rank, __TIM_cpu_id);

        for (int i = 0; i < __TIM_world_size; i++)
        {
            __TIM_shared_info = __TIM_cpu_id;
            MPI_Bcast(&__TIM_shared_info, 1, MPI_INT, i, MPI_COMM_WORLD);
            __TIM_shared_info_arr[i] = __TIM_shared_info;
            MPI_Barrier(MPI_COMM_WORLD);
        }
        
        printf("\n[%d]: After Bcast, __TIM_shared_info_arr is:\n", __TIM_world_rank);
        for (int i = 0; i < __TIM_world_size; i++)
        {
            printf("%d, ", __TIM_shared_info_arr[i]);
        }
        printf("\n");

        MPI_Finalize();
        return 0;
}
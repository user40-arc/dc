#include <stdio.h>
#include <mpi.h>

int main(int argc,char*argv[]){
    int rank, data[4]={10,20,30,40}, recv;

    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);

    if(rank==0){
        printf("Process 0 original data: ");
        for(int i=0;i<4;i++) printf("%d ",data[i]);
        printf("\n");
    }

    MPI_Scatter(data,1,MPI_INT,&recv,1,MPI_INT,0,MPI_COMM_WORLD);
    printf("Process %d received value %d\n",rank,recv);

    recv *= 2;

    MPI_Gather(&recv,1,MPI_INT,data,1,MPI_INT,0,MPI_COMM_WORLD);

    if(rank==0){
        printf("Process 0 gathered results: ");
        for(int i=0;i<4;i++) printf("%d ",data[i]);
        printf("\n");
    }

    MPI_Finalize();
}

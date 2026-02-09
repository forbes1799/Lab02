#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void print_array(int N, double *array){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            printf("%.4f ", array[i * N + j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main(void){
    const int N = 10;
    const int MAX_ITER = 10;

    double *room =      malloc(N * N * sizeof(double));
    double *new_room =  malloc(N * N * sizeof(double));

    int radiator_start = N * 0.2;
    int radiator_end   = N * 0.8;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            int idx = i * N + j;
            room[idx] = 10.0;
        }
    }
    
    for(int i = radiator_start; i < radiator_end; i++){
        int idx = i * N + (N-1);
        room[idx] =     100.0;
    }

    memcpy(new_room, room, N * N * sizeof(double));

    int iter = 0;

    //Main computation loop
    while(iter < MAX_ITER){
        
        /*=====================================================
        Implement the code here to implement the heat propagation
        You can use these for the 1D indices 
        

        int ij = i * N + j;
        int ipj = (i + 1) * N + j;//(i + 1, j)
        int imj = (i - 1) * N + j;//(i - 1, j)
        int ijp = i * N + j + 1;  //(i, j + 1)
        int ijm = i * N + j - 1;  //(i, j - 1)

        DO NOT WRITE TO BOUNDARY REGIONS
        ========================================================*/

        //Pointer swap to reduce memory movement
        double *temp = room;
        room = new_room;
        new_room = temp;

        //print_array(N, room);

        iter++;
    }
}


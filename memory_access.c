#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 16384
#define M 16384


static inline double time_diff(struct timespec start, struct timespec end)
{
    return (end.tv_sec - start.tv_sec)
         + (end.tv_nsec - start.tv_nsec) * 1e-9;
}

void workblock_1(const double *A, const double *B, double *C)
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int idx = i * M + j; //1D access for [i][j]
            C[idx] = A[idx] + B[idx];
        }
    }
}

void workblock_2(const double *A, const double *B, double *C)
{
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            int idx = j * M + i; //1D access for [j][i]
            C[idx] = A[idx] + B[idx];
        }
    }
}

int main(void)
{
    double *A = malloc(N * M * sizeof(double));
    double *B = malloc(N * M * sizeof(double));
    double *C = malloc(N * M * sizeof(double));

    /* Initialise matrices */
    for (int i = 0; i < N*M; i++) {
        A[i] = 1.0;
        B[i] = 2.0;
    }

    struct timespec t_start, t_end;
    double time_one, time_two;

    /* Workblock 1 */
    clock_gettime(CLOCK_MONOTONIC, &t_start);
    workblock_1(A, B, C);
    clock_gettime(CLOCK_MONOTONIC, &t_end);
    
    time_one = time_diff(t_start, t_end);

    printf("Workblock one time : %f seconds\n", time_one);

    /* Workblock 2 (same computation, different access order) */
    clock_gettime(CLOCK_MONOTONIC, &t_start);
    workblock_2(A, B, C);
    clock_gettime(CLOCK_MONOTONIC, &t_end);

    time_two = time_diff(t_start, t_end);

    printf("Workblock two time : %f seconds\n", time_two);

    free(A);
    free(B);
    free(C);

    return 0;
}

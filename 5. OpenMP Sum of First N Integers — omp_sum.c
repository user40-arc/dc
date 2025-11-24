#include <stdio.h>
#include <omp.h>

int main()
{
    int N = 100;
    int sum = 0;
    int i;

    #pragma omp parallel private(i) reduction(+:sum)
    {
        #pragma omp for
        for (i = 1; i <= N; i++) {
            sum = sum + i;
        }
    }

    printf("Sum of first %d integers = %d\n", N, sum);
    return 0;
}

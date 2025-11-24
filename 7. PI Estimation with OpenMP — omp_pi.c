#include <stdio.h>
#include <omp.h>

int main()
{
    long long N = 100000000;
    double pi = 0.0;

    #pragma omp parallel for reduction(+:pi)
    for (long long i = 0; i < N; i++) {
        double term = (double)((i % 2 == 0) ? 1 : -1) / (2 * i + 1);
        pi += term;
    }

    pi = 4.0 * pi;
    printf("Estimated value of PI = %.10f\n", pi);

    return 0;
}

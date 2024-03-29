	#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>

#include "read_data.hh"

#define N 2048

int main() {

    struct timeval inicio, final;
    double tiempo;
    gettimeofday(&inicio,NULL);

    double* A = importDOUBLE("A.txt",N,N);
    double* b = importDOUBLE("b.txt",N,N);
    double* res = (double *) malloc( sizeof(double) * N);
	
    int offset=0;
    int k;
    int i;
    for(k=0; k<N;k++){
        offset+=N;

        for(i=0; i<N; i++)
            res[k]+=A[offset+i]*b[i];

    }

    gettimeofday(&final,NULL);
    tiempo = (final.tv_sec-inicio.tv_sec+(final.tv_usec-inicio.tv_usec)/1.e6);

    printf("time: %.50lf \t",tiempo);
    for(int i = 0;i<N;i++)
        printf("%e     ",res[i]);

    free(A);
    free(b);
    free(res);
    return 0;
}

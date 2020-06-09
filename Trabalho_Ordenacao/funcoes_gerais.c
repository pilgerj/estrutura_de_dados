#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "funcoes_gerais.h"

void calculate_time(clock_t start_time, clock_t final_time) {
    double time_cost = ((double) (final_time - start_time)) / CLOCKS_PER_SEC;
    printf("Tempo gasto: %16.8lfs: \n",time_cost);
}

void monta_vetor(int A[]) {
    int i;
    srand(time(NULL));
    for (i=0; i<TAMANHO; i++)
        A[i] = rand()%TAMANHO;
}

void escreve_vetor(int A[], char *msg) {
    int i;
    printf("*********** %s ***********\n", msg);
    for (i=0; i<TAMANHO; i++)
        printf("%d ", A[i]);
    printf("\n");
}

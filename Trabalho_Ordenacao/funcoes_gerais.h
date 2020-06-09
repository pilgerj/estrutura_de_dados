#ifndef FUNCOES_GERAIS_H_INCLUDED
#define FUNCOES_GERAIS_H_INCLUDED

#include <time.h>

#define TAMANHO 10000

// Cabeçalho das Funções Gerais
void calculate_time(clock_t start_time, clock_t final_time);

void monta_vetor(int A[]);

void escreve_vetor(int A[], char *msg);

#endif // FUNCOES_GERAIS_H_INCLUDED

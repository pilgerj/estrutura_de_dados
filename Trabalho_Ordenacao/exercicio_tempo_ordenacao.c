#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "metodos_ordenacao.h"
#include "funcoes_gerais.h"

int main () {
    int A[TAMANHO];
    menu(A);
}

int menu(int A[]) {
    int opcao = 0;
    do {
        printf("Escolha o metodo de ordenacao: \n");
        printf("\t1 - bubble sort\n");
        printf("\t2 - selection sort\n");
        printf("\t3 - insertion sort\n");
        //printf("\t4 - merge sort\n");
        printf("\t5 - sair\n");
        scanf("%d", &opcao);
        monta_vetor(A);
        //escreve_vetor(A, "VETOR DESORDENADO");
        clock_t start_time = clock();
        switch (opcao) {
            case 1: bubble_sort(A); break;
            case 2: selection_sort(A); break;
            case 3: insertion_sort(A); break;
            //case 4: MERGE_SORT(A,0,TAMANHO-1); break;
            case 5: return;
        }
        clock_t final_time = clock();
        calculate_time(start_time,final_time);
        //escreve_vetor(A, "VETOR ORDENADO");
        system("pause");
        system("cls");

    } while (opcao >= 1 && opcao <= 5);
}

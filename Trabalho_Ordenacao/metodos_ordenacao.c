#include <stdio.h>
#include "metodos_ordenacao.h"
#include "funcoes_gerais.h"

void bubble_sort(int A[]) {
    int i,j,aux,trocou;
    for (i=1; i <TAMANHO; i++) {
       for (j=0; j<TAMANHO-i;j++) {
          if (A[j]>A[j+1]) {
             aux = A[j];
             A[j] = A[j+1];
             A[j+1] = aux;
          }
       }
   }
}

void selection_sort(int A[]) {
     int i, j, menor, aux;

     for (i=0; i< TAMANHO; i++) {
          menor  = i;
          for (j=i+1; j< TAMANHO; j++)
            if (A[j] < A[menor])
              menor = j;

          aux = A[menor];
          A[menor] = A[i];
          A[i] = aux;
     }
}

void insertion_sort(int A[]) {
    int i,j,k,key;
    for (j=1; j<TAMANHO; j++) {
      key = A[j];
      i = j-1;
      while (i >= 0 && A[i] > key) {
        A[i+1] = A[i];
        i = i-1;
      }
      A[i+1] = key;
    }
}

void merge(int A[], int p, int q, int r){
	int max = 999999;
	int n1 = q - p+1;  //define o tamanho do array L
	int n2 = r - q;		//define o tamanho do array R
	
	int L[n1+1];     
	for ( int i = 0; i<n1; i++){
		L[i] = A[p+i];   //preencher o array com os valor do meio para <
	}
	
	int R[n2+1];
	for (int j=0; j<n2; j++){
		R[j] = A[q+j+1];
	}
	
	L[n1] = max;
	R[n2] = max;
	
	i=1;
	j=1
	
	for (int k=p; k<=r; k++){
	if L[i] <= R[j]{
		A[k] = L[i];
		i = i+1;
		} 
	else{
		A[k] = R[j];
		j = j+1;
		}
	}
}

void merge_sort(int A[], int p, int r){
	if(p < r)
	{
	q = ((p+r)/2);
	merge_sort(A, p, q);
	merge_sort(A, q+1, r);
	merge(A, p, q, r);	
	} 
}

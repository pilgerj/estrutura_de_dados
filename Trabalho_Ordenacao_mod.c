#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAMANHO 200000

// CABECALHO //
int menu(int A[]);
void calculate_time(clock_t start_time, clock_t final_time);
void monta_vetor(int A[]);
void escreve_vetor(int A[], char *msg);
void bubble_sort(int A[]);
void selection_sort(int A[]);
void insertion_sort(int A[]);
void merge_sort(int A[], int p, int r);
void merge (int A[], int p, int q, int r);



int main () {
    int A[TAMANHO];
    menu(A);
}
 
int menu(int A[]) {
    int opcao = 0;
    do{
        printf("===================================\n");
        printf("Escolha o metodo de ordenacao: \n");
        printf("===================================\n");
		printf("\t1 - bubble sort\n");
        printf("\t2 - selection sort\n");
        printf("\t3 - insertion sort\n");
        printf("\t4 - merge sort\n");
        printf("\t5 - sair\n");
        printf("===================================\n");
        scanf("%d", &opcao);
        
		monta_vetor(A);
        clock_t start_time = clock();
        
		switch (opcao) 
		{
            case 1: bubble_sort(A); break;
            case 2: selection_sort(A); break;
            case 3: insertion_sort(A); break;
            case 4: merge_sort(A,0,TAMANHO-1); break;
            case 5: return 0;
        }
        clock_t final_time = clock();
        calculate_time(start_time,final_time);

    } while (opcao >= 1 && opcao <= 5); 
}

// UTILS //

void calculate_time(clock_t start_time, clock_t final_time) {
    double time_cost = ((double) (final_time - start_time)) / CLOCKS_PER_SEC;
    printf("\n Tempo de ordenacao: %16.8lfs: \n",time_cost);
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

// SORTS //

void bubble_sort(int A[]) 
{
    int i,j,aux;

    for (i=1; i <TAMANHO; i++) 
    {
       for (j=0; j<TAMANHO-i;j++) 
       {
          if (A[j]>A[j+1]) 
          {
             aux = A[j];
             A[j] = A[j+1];
             A[j+1] = aux;
          }
       }
   }
}

void selection_sort(int A[]) 
{
     int i, j, men, aux;

     for (i=0; i< TAMANHO; i++) 
     {
          men = i;
          for (j=i+1; j< TAMANHO; j++)
            if (A[j] < A[men])
              men = j;

          aux = A[men];
          A[men] = A[i];
          A[i] = aux;
     }
}

void insertion_sort(int A[]) 
{
    int i,j,k,key;

    for (j=1; j<TAMANHO; j++) 
    {
      key = A[j];
      i = j-1;
      while (i >= 0 && A[i] > key) 
      {
        A[i+1] = A[i];
        i = i-1;
      }
      A[i+1] = key;
    }
}

void merge(int A[], int p, int q, int r)
{
	int i,j,k;
	
	int n1=q-p+1;  
	int n2=r-q;		
	
	int L[n1];     
    for (i=0; i<n1; i++)
    {
		L[i] = A[p+i];   
	}
	
	int R[n2];
    for (j=0; j<n2; j++)
    {
		R[j] = A[q+1+j];
	}
	
	i = 0; 
    j = 0; 
    k = p; 
    
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            A[k] = L[i];
            i++;
        }
        else
        {
            A[k] = R[j];
            j++;
        }
        k++;
    }
 
    while (i < n1)
    {
        A[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        A[k] = R[j];
        j++;
        k++;
    }
}


void merge_sort(int A[], int p, int r)
{
	int q;
	if(p < r)
	{
	q = ((p+r)/2);
	merge_sort(A, p, q);
    merge_sort(A, q+1, r);
    merge(A, p, q, r);
	} 
}
